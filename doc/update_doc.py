import os
import errno
import shutil
import argparse
import re
import markdown

def inputs() -> str:
    """Returns the list of input signals from the OBC to the mBox software.
    
    Returns:
        list: List of input signals
    """
    return [
        'RTE_GNC_X_POSITION_LAUNCHPAD',
        'RTE_GNC_Y_POSITION_LAUNCHPAD',
        'RTE_GNC_Z_POSITION_LAUNCHPAD',
        'RTE_GNC_X_VELOCITY_LAUNCHPAD',
        'RTE_GNC_Y_VELOCITY_LAUNCHPAD',
        'RTE_GNC_Z_VELOCITY_LAUNCHPAD',
        'RTE_GNC_ROLL_ANGLE_BODY',
        'RTE_GNC_PITCH_ANGLE_BODY',
        'RTE_GNC_YAW_ANGLE_BODY',
        'RTE_GNC_OMEGA_X_BODY',
        'RTE_GNC_OMEGA_Y_BODY',
        'RTE_GNC_OMEGA_Z_BODY',
        'RTE_GNC_MASS',
        'RTE_GNC_CoM_X_M',
        'RTE_GNC_CoM_Y_M',
        'RTE_GNC_CoM_Z_M',
        'RTE_GNC_MISSION_STATUS',
        'RTE_MONITOR_WALL_CLOCK'
    ]

def recoverInputSignals(filestr : str) -> dict:
    """Returns dictionary of input signal IDs from the incaslib header file.
    
    Args:
        filestr (str): String containing the contents of the incaslib header file.
    
    Returns:
        dict: Dictionary containing the input signal names (keys) and input signal IDs (values).
    """
    ids = dict()
    for i in inputs():
        ids[i] = re.search(r'#define {0} (\d+)'.format(i), filestr).group(1)

    return ids 

def outputs() -> str:
    """Returns the list of output signals from the mBox software to the OBC.
    
    Returns:
        list: List of output signals
    """
    return [
        'RTE_EMBOTECH_PAC_STATUS_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_POSITION_UP_M_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_POSITION_EAST_M_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_POSITION_NORTH_M_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_X_MS_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_Y_MS_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_VELOCITY_Z_MS_SIGNAL',
        'RTE_EMBOTECH_PAC_REFERENCE_TIMESTAMP'
    ]

def recoverOutputSignals(filestr: str) -> dict:
    """Returns dictionary of output signal IDs from the incaslib header file.
    
    Args:
        filestr (str): String containing the contents of the incaslib header file.
    
    Returns:
        dict: Dictionary containing the output signal names (keys) and output signal IDs (values).
    """
    ids = dict()
    for o in outputs():
        ids[o]  = re.search(r'#define {0} (\d+)'.format(o), filestr).group(1)

    return ids 

def recoverErrorCodes(filestr: str) -> list:
    """Returns list of OBRTTG error codes defined by their name, ID and description. The list contains dictionaries.
    Each dictionary has the following fields defining the specific error:
       - name
       - id
       - description
    
    Args:
        filestr (str): String containing the contents of the Obrttg header file.
    
    Returns:
        list: List of error codes
    """
    err = [] 
    pat = r"static constexpr uint16_t (?P<error_name>.+) = (?P<id>\d+)u;.+///< (?P<description>.+)"

    for l in filestr.split('\n'):
        m = re.match(pat, l)
        if m:
            err.append({
                'name' : m.group('error_name'),
                'id' : m.group('id'),
                'description' : m.group('description')
            })

    return err

def readIncaslibHeader() -> str:
    """Reads the contents of the incaslib header file
    
    Returns:
        str: Contents of the incaslib header file.
    """
    curdir = os.path.dirname(os.path.abspath(__file__))
    header = os.path.join(curdir, '..', 'communication', 'incaslib', 'include', 'incaslib.h')
    with open(header, 'r') as fin:
        return fin.read()

def readObrttgHeader() -> str:
    """Reads the contents of the Obrttg header file
    
    Returns:
        str: Contents of the Obrttg header file.
    """
    curdir = os.path.dirname(os.path.abspath(__file__))
    header = os.path.join(curdir, '..', 'obrttg', 'include', 'obrttg.hpp')
    with open(header, 'r') as fin:
        return fin.read()
def updateVersion(readme: str) -> str:
    """Updates the mbox-obrttg-software version string in the readme file.

    Args:
        readme (str): Contents of the template readme file before replacing the version token.
    
    Returns:
        str: Contents of the template readme file after replacing the version token.
    """
    curdir = os.path.dirname(os.path.abspath(__file__))
    verfile = os.path.join(curdir, '..', 'VERSION')
    with open(verfile, 'r') as fin:
        version = fin.read()
    
    readme = readme.replace("$TKN_VERSION", version)

    return readme

def updateErrorCodes(readme: str) -> str:
    """Updates the list of Obrttg error codes in the readme file.

    Args:
        readme (str): Contents of the template readme file before replacing the error code token.
    
    Returns:
        str: Contents of the template readme file after replacing the error code token.
    """
    hdr = readObrttgHeader()
    errcodes = recoverErrorCodes(hdr)
    errstr = ''
    for e in errcodes:
        errstr += '| {0} | `{1}` | {2} |\n'.format(e['id'], e['name'], e['description'])
    
    readme = readme.replace("$TKN_ERROR_CODES", errstr)

    return readme

def updateInterface(readme : str) -> str:
    """Updates the list of incaslib input/output interface in the readme file.

    Args:
        readme (str): Contents of the template readme file before replacing input / output signal IDs tokens.
    
    Returns:
        str: Contents of the template readme file after replacing the input / output signal IDs tokens.
    """
    hdr = readIncaslibHeader()
    inputIds = recoverInputSignals(hdr)
    outputIds = recoverOutputSignals(hdr)

    for i in inputs():
        readme = readme.replace("${0}".format(i), inputIds[i])

    for o in outputs():
        readme = readme.replace("${0}".format(o), outputIds[o])

    return readme

def loadReadme() -> str:
    """Reads the contents of the release README template file.
    
    Returns:
        str: Contents of the release README template file.
    """
    curdir = os.path.dirname(os.path.abspath(__file__))
    with open(os.path.join(curdir, 'README_template.md'), 'r') as fin:
        return fin.read()

def md2html(md) -> str:
    """Generates html from the provided markdown string.

    Args:
        md (str): Contents of the markdown file.
    
    Returns:
        str: Contents of the resulting html file.
    """

    # Generate css styles string
    cssdir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'styles')
    css = ['default.css', 'github.css']
    style = ''
    for c in css:
        with open(os.path.join(cssdir, c), 'r') as fin:
            style +=''' 
    <style>
    {0}
    </style>'''.format(fin.read())

    # Convert markdown to html
    # Define extensions to use
    exts = ['extra', 'codehilite', 'tables', 'sane_lists', 'toc']
    # Generate final html
    return '''
    <html lang="eng">
    <head>
    <meta content="text/html; charset=utf-8" http-equiv="content-type" />
    {0}
    </head>
    <body>
    {1} 
    </body>
    </html>
    '''.format(style, markdown.markdown(md, extensions=exts))
    
def main() -> None:
    """Generates mBox documentation: README files in .md and html format.
    """
    parser = argparse.ArgumentParser(
        usage="python3 %(prog)s [OPTIONS] OUTDIR",
        description="Updates the release README markdown file and saves it to the specified directory."
    )

    parser.add_argument('outdir',
        metavar='OUTDIR',
        type=str,
        nargs=1,
        help='Full path to the directory where the resulting README.md file is stored.')

    args = parser.parse_args()

    # Load readme template
    readme = loadReadme()

    # Replace input/output interface tokens
    readme = updateInterface(readme)

    # Replace error codes tokens
    readme = updateErrorCodes(readme)

    # Replace version token
    readme = updateVersion(readme)

    # Check that directory exists
    if not os.path.exists(args.outdir[0]):
        raise FileNotFoundError(errno.ENOENT, os.strerror(errno.ENOENT), args.outdir[0]) 

    # Create doc subdirectory
    docdir = os.path.join(args.outdir[0], 'doc')
    if not os.path.exists(docdir):
        os.mkdir(docdir)
    else:
        shutil.rmtree(docdir)
        os.mkdir(docdir)

    # Copy assets to output directory 
    srcdir = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'assets')
    shutil.copytree(srcdir, os.path.join(docdir, "assets")) 

    # Write resulting .md to the specified directory 
    with open(os.path.join(docdir, "README.md"), 'w') as ouf:
        ouf.write(readme)
    
    # Save README also in html format
    with open(os.path.join(docdir, "README.html"), 'w') as ouf:
        ouf.write(md2html(readme))


if __name__ == "__main__":
    main()