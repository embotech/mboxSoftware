#pragma once
// MESSAGE ACK PACKING

#define MAVLINK_MSG_ID_ACK 5


typedef struct __mavlink_ack_t {
 uint32_t signal; /*<  Signal ID*/
 uint8_t node_id; /*<  Node ID*/
} mavlink_ack_t;

#define MAVLINK_MSG_ID_ACK_LEN 5
#define MAVLINK_MSG_ID_ACK_MIN_LEN 5
#define MAVLINK_MSG_ID_5_LEN 5
#define MAVLINK_MSG_ID_5_MIN_LEN 5

#define MAVLINK_MSG_ID_ACK_CRC 227
#define MAVLINK_MSG_ID_5_CRC 227



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ACK { \
    5, \
    "ACK", \
    2, \
    {  { "signal", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ack_t, signal) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ack_t, node_id) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ACK { \
    "ACK", \
    2, \
    {  { "signal", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ack_t, signal) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 4, offsetof(mavlink_ack_t, node_id) }, \
         } \
}
#endif

/**
 * @brief Pack a ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param signal  Signal ID
 * @param node_id  Node ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ack_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t signal, uint8_t node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACK_LEN];
    _mav_put_uint32_t(buf, 0, signal);
    _mav_put_uint8_t(buf, 4, node_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACK_LEN);
#else
    mavlink_ack_t packet;
    packet.signal = signal;
    packet.node_id = node_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACK;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
}

/**
 * @brief Pack a ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param signal  Signal ID
 * @param node_id  Node ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ack_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t signal,uint8_t node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACK_LEN];
    _mav_put_uint32_t(buf, 0, signal);
    _mav_put_uint8_t(buf, 4, node_id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ACK_LEN);
#else
    mavlink_ack_t packet;
    packet.signal = signal;
    packet.node_id = node_id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ACK;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
}

/**
 * @brief Encode a ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ack_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ack_t* ack)
{
    return mavlink_msg_ack_pack(system_id, component_id, msg, ack->signal, ack->node_id);
}

/**
 * @brief Encode a ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ack_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ack_t* ack)
{
    return mavlink_msg_ack_pack_chan(system_id, component_id, chan, msg, ack->signal, ack->node_id);
}

/**
 * @brief Send a ack message
 * @param chan MAVLink channel to send the message
 *
 * @param signal  Signal ID
 * @param node_id  Node ID
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ack_send(mavlink_channel_t chan, uint32_t signal, uint8_t node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ACK_LEN];
    _mav_put_uint32_t(buf, 0, signal);
    _mav_put_uint8_t(buf, 4, node_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK, buf, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
#else
    mavlink_ack_t packet;
    packet.signal = signal;
    packet.node_id = node_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK, (const char *)&packet, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
#endif
}

/**
 * @brief Send a ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ack_send_struct(mavlink_channel_t chan, const mavlink_ack_t* ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ack_send(chan, ack->signal, ack->node_id);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK, (const char *)ack, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t signal, uint8_t node_id)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, signal);
    _mav_put_uint8_t(buf, 4, node_id);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK, buf, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
#else
    mavlink_ack_t *packet = (mavlink_ack_t *)msgbuf;
    packet->signal = signal;
    packet->node_id = node_id;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ACK, (const char *)packet, MAVLINK_MSG_ID_ACK_MIN_LEN, MAVLINK_MSG_ID_ACK_LEN, MAVLINK_MSG_ID_ACK_CRC);
#endif
}
#endif

#endif

// MESSAGE ACK UNPACKING


/**
 * @brief Get field signal from ack message
 *
 * @return  Signal ID
 */
static inline uint32_t mavlink_msg_ack_get_signal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field node_id from ack message
 *
 * @return  Node ID
 */
static inline uint8_t mavlink_msg_ack_get_node_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a ack message into a struct
 *
 * @param msg The message to decode
 * @param ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_ack_decode(const mavlink_message_t* msg, mavlink_ack_t* ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ack->signal = mavlink_msg_ack_get_signal(msg);
    ack->node_id = mavlink_msg_ack_get_node_id(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ACK_LEN? msg->len : MAVLINK_MSG_ID_ACK_LEN;
        memset(ack, 0, MAVLINK_MSG_ID_ACK_LEN);
    memcpy(ack, _MAV_PAYLOAD(msg), len);
#endif
}
