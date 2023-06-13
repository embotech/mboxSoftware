/** @file
 *  @brief MAVLink comm protocol generated from incas.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_INCAS_H
#define MAVLINK_INCAS_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_INCAS.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{1, 128, 23, 23, 0, 0, 0}, {3, 21, 163, 163, 0, 0, 0}, {4, 197, 7, 7, 0, 0, 0}, {5, 227, 5, 5, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_INCAS

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_SYS_CONFIG
#define HAVE_ENUM_SYS_CONFIG
typedef enum SYS_CONFIG
{
   UDP_BROADCAST_PORT=7858, /*  | */
   SYS_CONFIG_ENUM_END=7859, /*  | */
} SYS_CONFIG;
#endif

/** @brief  */
#ifndef HAVE_ENUM_NODES_ID
#define HAVE_ENUM_NODES_ID
typedef enum NODES_ID
{
   PRIMARY_OBC_NODE_ID=1, /*  | */
   SECONDARY_OBC_NODE_ID=2, /*  | */
   PRIMARY_PRSC_NODE_ID=4, /*  | */
   SECONDARY_PRSC_NODE_ID=8, /*  | */
   GROUND_STATION_NODE_ID=16, /*  | */
   NODES_ID_ENUM_END=17, /*  | */
} NODES_ID;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 1
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_signal.h"
#include "./mavlink_msg_fault.h"
#include "./mavlink_msg_ids.h"
#include "./mavlink_msg_ack.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_SIGNAL, MAVLINK_MESSAGE_INFO_FAULT, MAVLINK_MESSAGE_INFO_IDS, MAVLINK_MESSAGE_INFO_ACK}
# define MAVLINK_MESSAGE_NAMES {{ "ACK", 5 }, { "FAULT", 3 }, { "IDS", 4 }, { "SIGNAL", 1 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_INCAS_H
