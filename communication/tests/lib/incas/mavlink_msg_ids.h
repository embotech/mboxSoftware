#pragma once
// MESSAGE IDS PACKING

#define MAVLINK_MSG_ID_IDS 4


typedef struct __mavlink_ids_t {
 uint32_t frame_id; /*<  Frame ID*/
 uint8_t node_id; /*<  Node ID*/
 uint8_t hardware_revision; /*<  Hardware Revision*/
 uint8_t software_revision; /*<  Software Revision*/
} mavlink_ids_t;

#define MAVLINK_MSG_ID_IDS_LEN 7
#define MAVLINK_MSG_ID_IDS_MIN_LEN 7
#define MAVLINK_MSG_ID_4_LEN 7
#define MAVLINK_MSG_ID_4_MIN_LEN 7

#define MAVLINK_MSG_ID_IDS_CRC 197
#define MAVLINK_MSG_ID_4_CRC 197



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_IDS { \
    4, \
    "IDS", \
    4, \
    {  { "frame_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ids_t, frame_id) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ids_t, node_id) }, \
         { "hardware_revision", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_ids_t, hardware_revision) }, \
         { "software_revision", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_ids_t, software_revision) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_IDS { \
    "IDS", \
    4, \
    {  { "frame_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ids_t, frame_id) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ids_t, node_id) }, \
         { "hardware_revision", NULL, MAVLINK_TYPE_UINT8_T, 0, 5, offsetof(mavlink_ids_t, hardware_revision) }, \
         { "software_revision", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_ids_t, software_revision) }, \
         } \
}
#endif

/**
 * @brief Pack a ids message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param frame_id  Frame ID
 * @param node_id  Node ID
 * @param hardware_revision  Hardware Revision
 * @param software_revision  Software Revision
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ids_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t frame_id, uint8_t node_id, uint8_t hardware_revision, uint8_t software_revision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IDS_LEN];
    _mav_put_uint32_t(buf, 0, frame_id);
    _mav_put_uint8_t(buf, 4, node_id);
    _mav_put_uint8_t(buf, 5, hardware_revision);
    _mav_put_uint8_t(buf, 6, software_revision);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IDS_LEN);
#else
    mavlink_ids_t packet;
    packet.frame_id = frame_id;
    packet.node_id = node_id;
    packet.hardware_revision = hardware_revision;
    packet.software_revision = software_revision;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IDS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IDS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
}

/**
 * @brief Pack a ids message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param frame_id  Frame ID
 * @param node_id  Node ID
 * @param hardware_revision  Hardware Revision
 * @param software_revision  Software Revision
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ids_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t frame_id,uint8_t node_id,uint8_t hardware_revision,uint8_t software_revision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IDS_LEN];
    _mav_put_uint32_t(buf, 0, frame_id);
    _mav_put_uint8_t(buf, 4, node_id);
    _mav_put_uint8_t(buf, 5, hardware_revision);
    _mav_put_uint8_t(buf, 6, software_revision);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_IDS_LEN);
#else
    mavlink_ids_t packet;
    packet.frame_id = frame_id;
    packet.node_id = node_id;
    packet.hardware_revision = hardware_revision;
    packet.software_revision = software_revision;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_IDS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_IDS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
}

/**
 * @brief Encode a ids struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ids C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ids_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ids_t* ids)
{
    return mavlink_msg_ids_pack(system_id, component_id, msg, ids->frame_id, ids->node_id, ids->hardware_revision, ids->software_revision);
}

/**
 * @brief Encode a ids struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ids C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ids_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ids_t* ids)
{
    return mavlink_msg_ids_pack_chan(system_id, component_id, chan, msg, ids->frame_id, ids->node_id, ids->hardware_revision, ids->software_revision);
}

/**
 * @brief Send a ids message
 * @param chan MAVLink channel to send the message
 *
 * @param frame_id  Frame ID
 * @param node_id  Node ID
 * @param hardware_revision  Hardware Revision
 * @param software_revision  Software Revision
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ids_send(mavlink_channel_t chan, uint32_t frame_id, uint8_t node_id, uint8_t hardware_revision, uint8_t software_revision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_IDS_LEN];
    _mav_put_uint32_t(buf, 0, frame_id);
    _mav_put_uint8_t(buf, 4, node_id);
    _mav_put_uint8_t(buf, 5, hardware_revision);
    _mav_put_uint8_t(buf, 6, software_revision);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IDS, buf, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
#else
    mavlink_ids_t packet;
    packet.frame_id = frame_id;
    packet.node_id = node_id;
    packet.hardware_revision = hardware_revision;
    packet.software_revision = software_revision;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IDS, (const char *)&packet, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
#endif
}

/**
 * @brief Send a ids message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ids_send_struct(mavlink_channel_t chan, const mavlink_ids_t* ids)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ids_send(chan, ids->frame_id, ids->node_id, ids->hardware_revision, ids->software_revision);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IDS, (const char *)ids, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
#endif
}

#if MAVLINK_MSG_ID_IDS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ids_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t frame_id, uint8_t node_id, uint8_t hardware_revision, uint8_t software_revision)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, frame_id);
    _mav_put_uint8_t(buf, 4, node_id);
    _mav_put_uint8_t(buf, 5, hardware_revision);
    _mav_put_uint8_t(buf, 6, software_revision);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IDS, buf, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
#else
    mavlink_ids_t *packet = (mavlink_ids_t *)msgbuf;
    packet->frame_id = frame_id;
    packet->node_id = node_id;
    packet->hardware_revision = hardware_revision;
    packet->software_revision = software_revision;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_IDS, (const char *)packet, MAVLINK_MSG_ID_IDS_MIN_LEN, MAVLINK_MSG_ID_IDS_LEN, MAVLINK_MSG_ID_IDS_CRC);
#endif
}
#endif

#endif

// MESSAGE IDS UNPACKING


/**
 * @brief Get field frame_id from ids message
 *
 * @return  Frame ID
 */
static inline uint32_t mavlink_msg_ids_get_frame_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field node_id from ids message
 *
 * @return  Node ID
 */
static inline uint8_t mavlink_msg_ids_get_node_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field hardware_revision from ids message
 *
 * @return  Hardware Revision
 */
static inline uint8_t mavlink_msg_ids_get_hardware_revision(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field software_revision from ids message
 *
 * @return  Software Revision
 */
static inline uint8_t mavlink_msg_ids_get_software_revision(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Decode a ids message into a struct
 *
 * @param msg The message to decode
 * @param ids C-struct to decode the message contents into
 */
static inline void mavlink_msg_ids_decode(const mavlink_message_t* msg, mavlink_ids_t* ids)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ids->frame_id = mavlink_msg_ids_get_frame_id(msg);
    ids->node_id = mavlink_msg_ids_get_node_id(msg);
    ids->hardware_revision = mavlink_msg_ids_get_hardware_revision(msg);
    ids->software_revision = mavlink_msg_ids_get_software_revision(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_IDS_LEN? msg->len : MAVLINK_MSG_ID_IDS_LEN;
        memset(ids, 0, MAVLINK_MSG_ID_IDS_LEN);
    memcpy(ids, _MAV_PAYLOAD(msg), len);
#endif
}
