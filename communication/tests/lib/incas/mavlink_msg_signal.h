#pragma once
// MESSAGE SIGNAL PACKING

#define MAVLINK_MSG_ID_SIGNAL 1


typedef struct __mavlink_signal_t {
 uint64_t data; /*<  Data field*/
 uint64_t timestamp; /*<  Signal timestamp*/
 uint32_t signal_id; /*<  Signal ID*/
 uint8_t dest_node; /*<  Destination Node ID*/
 uint8_t source_node; /*<  Source Node ID*/
 uint8_t active_time; /*<  The signal active time given in ms*/
} mavlink_signal_t;

#define MAVLINK_MSG_ID_SIGNAL_LEN 23
#define MAVLINK_MSG_ID_SIGNAL_MIN_LEN 23
#define MAVLINK_MSG_ID_1_LEN 23
#define MAVLINK_MSG_ID_1_MIN_LEN 23

#define MAVLINK_MSG_ID_SIGNAL_CRC 128
#define MAVLINK_MSG_ID_1_CRC 128



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SIGNAL { \
    1, \
    "SIGNAL", \
    6, \
    {  { "signal_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_signal_t, signal_id) }, \
         { "dest_node", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_signal_t, dest_node) }, \
         { "source_node", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_signal_t, source_node) }, \
         { "data", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_signal_t, data) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_signal_t, timestamp) }, \
         { "active_time", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_signal_t, active_time) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SIGNAL { \
    "SIGNAL", \
    6, \
    {  { "signal_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_signal_t, signal_id) }, \
         { "dest_node", NULL, MAVLINK_TYPE_UINT8_T, 0, 20, offsetof(mavlink_signal_t, dest_node) }, \
         { "source_node", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_signal_t, source_node) }, \
         { "data", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_signal_t, data) }, \
         { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_signal_t, timestamp) }, \
         { "active_time", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_signal_t, active_time) }, \
         } \
}
#endif

/**
 * @brief Pack a signal message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param signal_id  Signal ID
 * @param dest_node  Destination Node ID
 * @param source_node  Source Node ID
 * @param data  Data field
 * @param timestamp  Signal timestamp
 * @param active_time  The signal active time given in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t signal_id, uint8_t dest_node, uint8_t source_node, uint64_t data, uint64_t timestamp, uint8_t active_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SIGNAL_LEN];
    _mav_put_uint64_t(buf, 0, data);
    _mav_put_uint64_t(buf, 8, timestamp);
    _mav_put_uint32_t(buf, 16, signal_id);
    _mav_put_uint8_t(buf, 20, dest_node);
    _mav_put_uint8_t(buf, 21, source_node);
    _mav_put_uint8_t(buf, 22, active_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_LEN);
#else
    mavlink_signal_t packet;
    packet.data = data;
    packet.timestamp = timestamp;
    packet.signal_id = signal_id;
    packet.dest_node = dest_node;
    packet.source_node = source_node;
    packet.active_time = active_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SIGNAL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
}

/**
 * @brief Pack a signal message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param signal_id  Signal ID
 * @param dest_node  Destination Node ID
 * @param source_node  Source Node ID
 * @param data  Data field
 * @param timestamp  Signal timestamp
 * @param active_time  The signal active time given in ms
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_signal_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t signal_id,uint8_t dest_node,uint8_t source_node,uint64_t data,uint64_t timestamp,uint8_t active_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SIGNAL_LEN];
    _mav_put_uint64_t(buf, 0, data);
    _mav_put_uint64_t(buf, 8, timestamp);
    _mav_put_uint32_t(buf, 16, signal_id);
    _mav_put_uint8_t(buf, 20, dest_node);
    _mav_put_uint8_t(buf, 21, source_node);
    _mav_put_uint8_t(buf, 22, active_time);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SIGNAL_LEN);
#else
    mavlink_signal_t packet;
    packet.data = data;
    packet.timestamp = timestamp;
    packet.signal_id = signal_id;
    packet.dest_node = dest_node;
    packet.source_node = source_node;
    packet.active_time = active_time;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SIGNAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SIGNAL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
}

/**
 * @brief Encode a signal struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param signal C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_signal_t* signal)
{
    return mavlink_msg_signal_pack(system_id, component_id, msg, signal->signal_id, signal->dest_node, signal->source_node, signal->data, signal->timestamp, signal->active_time);
}

/**
 * @brief Encode a signal struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param signal C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_signal_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_signal_t* signal)
{
    return mavlink_msg_signal_pack_chan(system_id, component_id, chan, msg, signal->signal_id, signal->dest_node, signal->source_node, signal->data, signal->timestamp, signal->active_time);
}

/**
 * @brief Send a signal message
 * @param chan MAVLink channel to send the message
 *
 * @param signal_id  Signal ID
 * @param dest_node  Destination Node ID
 * @param source_node  Source Node ID
 * @param data  Data field
 * @param timestamp  Signal timestamp
 * @param active_time  The signal active time given in ms
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_signal_send(mavlink_channel_t chan, uint32_t signal_id, uint8_t dest_node, uint8_t source_node, uint64_t data, uint64_t timestamp, uint8_t active_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SIGNAL_LEN];
    _mav_put_uint64_t(buf, 0, data);
    _mav_put_uint64_t(buf, 8, timestamp);
    _mav_put_uint32_t(buf, 16, signal_id);
    _mav_put_uint8_t(buf, 20, dest_node);
    _mav_put_uint8_t(buf, 21, source_node);
    _mav_put_uint8_t(buf, 22, active_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL, buf, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
#else
    mavlink_signal_t packet;
    packet.data = data;
    packet.timestamp = timestamp;
    packet.signal_id = signal_id;
    packet.dest_node = dest_node;
    packet.source_node = source_node;
    packet.active_time = active_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL, (const char *)&packet, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
#endif
}

/**
 * @brief Send a signal message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_signal_send_struct(mavlink_channel_t chan, const mavlink_signal_t* signal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_signal_send(chan, signal->signal_id, signal->dest_node, signal->source_node, signal->data, signal->timestamp, signal->active_time);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL, (const char *)signal, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
#endif
}

#if MAVLINK_MSG_ID_SIGNAL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_signal_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t signal_id, uint8_t dest_node, uint8_t source_node, uint64_t data, uint64_t timestamp, uint8_t active_time)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, data);
    _mav_put_uint64_t(buf, 8, timestamp);
    _mav_put_uint32_t(buf, 16, signal_id);
    _mav_put_uint8_t(buf, 20, dest_node);
    _mav_put_uint8_t(buf, 21, source_node);
    _mav_put_uint8_t(buf, 22, active_time);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL, buf, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
#else
    mavlink_signal_t *packet = (mavlink_signal_t *)msgbuf;
    packet->data = data;
    packet->timestamp = timestamp;
    packet->signal_id = signal_id;
    packet->dest_node = dest_node;
    packet->source_node = source_node;
    packet->active_time = active_time;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SIGNAL, (const char *)packet, MAVLINK_MSG_ID_SIGNAL_MIN_LEN, MAVLINK_MSG_ID_SIGNAL_LEN, MAVLINK_MSG_ID_SIGNAL_CRC);
#endif
}
#endif

#endif

// MESSAGE SIGNAL UNPACKING


/**
 * @brief Get field signal_id from signal message
 *
 * @return  Signal ID
 */
static inline uint32_t mavlink_msg_signal_get_signal_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field dest_node from signal message
 *
 * @return  Destination Node ID
 */
static inline uint8_t mavlink_msg_signal_get_dest_node(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field source_node from signal message
 *
 * @return  Source Node ID
 */
static inline uint8_t mavlink_msg_signal_get_source_node(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field data from signal message
 *
 * @return  Data field
 */
static inline uint64_t mavlink_msg_signal_get_data(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field timestamp from signal message
 *
 * @return  Signal timestamp
 */
static inline uint64_t mavlink_msg_signal_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field active_time from signal message
 *
 * @return  The signal active time given in ms
 */
static inline uint8_t mavlink_msg_signal_get_active_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Decode a signal message into a struct
 *
 * @param msg The message to decode
 * @param signal C-struct to decode the message contents into
 */
static inline void mavlink_msg_signal_decode(const mavlink_message_t* msg, mavlink_signal_t* signal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    signal->data = mavlink_msg_signal_get_data(msg);
    signal->timestamp = mavlink_msg_signal_get_timestamp(msg);
    signal->signal_id = mavlink_msg_signal_get_signal_id(msg);
    signal->dest_node = mavlink_msg_signal_get_dest_node(msg);
    signal->source_node = mavlink_msg_signal_get_source_node(msg);
    signal->active_time = mavlink_msg_signal_get_active_time(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SIGNAL_LEN? msg->len : MAVLINK_MSG_ID_SIGNAL_LEN;
        memset(signal, 0, MAVLINK_MSG_ID_SIGNAL_LEN);
    memcpy(signal, _MAV_PAYLOAD(msg), len);
#endif
}
