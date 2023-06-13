#pragma once
// MESSAGE FAULT PACKING

#define MAVLINK_MSG_ID_FAULT 3


typedef struct __mavlink_fault_t {
 uint8_t component; /*<  Frame ID*/
 uint8_t node_id; /*<  Node ID*/
 char error_message[161]; /*<  Null terminated Error Message*/
} mavlink_fault_t;

#define MAVLINK_MSG_ID_FAULT_LEN 163
#define MAVLINK_MSG_ID_FAULT_MIN_LEN 163
#define MAVLINK_MSG_ID_3_LEN 163
#define MAVLINK_MSG_ID_3_MIN_LEN 163

#define MAVLINK_MSG_ID_FAULT_CRC 21
#define MAVLINK_MSG_ID_3_CRC 21

#define MAVLINK_MSG_FAULT_FIELD_ERROR_MESSAGE_LEN 161

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_FAULT { \
    3, \
    "FAULT", \
    3, \
    {  { "component", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_fault_t, component) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_fault_t, node_id) }, \
         { "error_message", NULL, MAVLINK_TYPE_CHAR, 161, 2, offsetof(mavlink_fault_t, error_message) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_FAULT { \
    "FAULT", \
    3, \
    {  { "component", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_fault_t, component) }, \
         { "node_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_fault_t, node_id) }, \
         { "error_message", NULL, MAVLINK_TYPE_CHAR, 161, 2, offsetof(mavlink_fault_t, error_message) }, \
         } \
}
#endif

/**
 * @brief Pack a fault message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param component  Frame ID
 * @param node_id  Node ID
 * @param error_message  Null terminated Error Message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fault_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t component, uint8_t node_id, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FAULT_LEN];
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, node_id);
    _mav_put_char_array(buf, 2, error_message, 161);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FAULT_LEN);
#else
    mavlink_fault_t packet;
    packet.component = component;
    packet.node_id = node_id;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*161);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FAULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FAULT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
}

/**
 * @brief Pack a fault message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param component  Frame ID
 * @param node_id  Node ID
 * @param error_message  Null terminated Error Message
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_fault_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t component,uint8_t node_id,const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FAULT_LEN];
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, node_id);
    _mav_put_char_array(buf, 2, error_message, 161);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_FAULT_LEN);
#else
    mavlink_fault_t packet;
    packet.component = component;
    packet.node_id = node_id;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*161);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_FAULT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_FAULT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
}

/**
 * @brief Encode a fault struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param fault C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fault_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_fault_t* fault)
{
    return mavlink_msg_fault_pack(system_id, component_id, msg, fault->component, fault->node_id, fault->error_message);
}

/**
 * @brief Encode a fault struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param fault C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_fault_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_fault_t* fault)
{
    return mavlink_msg_fault_pack_chan(system_id, component_id, chan, msg, fault->component, fault->node_id, fault->error_message);
}

/**
 * @brief Send a fault message
 * @param chan MAVLink channel to send the message
 *
 * @param component  Frame ID
 * @param node_id  Node ID
 * @param error_message  Null terminated Error Message
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_fault_send(mavlink_channel_t chan, uint8_t component, uint8_t node_id, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_FAULT_LEN];
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, node_id);
    _mav_put_char_array(buf, 2, error_message, 161);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FAULT, buf, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
#else
    mavlink_fault_t packet;
    packet.component = component;
    packet.node_id = node_id;
    mav_array_memcpy(packet.error_message, error_message, sizeof(char)*161);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FAULT, (const char *)&packet, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
#endif
}

/**
 * @brief Send a fault message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_fault_send_struct(mavlink_channel_t chan, const mavlink_fault_t* fault)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_fault_send(chan, fault->component, fault->node_id, fault->error_message);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FAULT, (const char *)fault, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
#endif
}

#if MAVLINK_MSG_ID_FAULT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_fault_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t component, uint8_t node_id, const char *error_message)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, component);
    _mav_put_uint8_t(buf, 1, node_id);
    _mav_put_char_array(buf, 2, error_message, 161);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FAULT, buf, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
#else
    mavlink_fault_t *packet = (mavlink_fault_t *)msgbuf;
    packet->component = component;
    packet->node_id = node_id;
    mav_array_memcpy(packet->error_message, error_message, sizeof(char)*161);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_FAULT, (const char *)packet, MAVLINK_MSG_ID_FAULT_MIN_LEN, MAVLINK_MSG_ID_FAULT_LEN, MAVLINK_MSG_ID_FAULT_CRC);
#endif
}
#endif

#endif

// MESSAGE FAULT UNPACKING


/**
 * @brief Get field component from fault message
 *
 * @return  Frame ID
 */
static inline uint8_t mavlink_msg_fault_get_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field node_id from fault message
 *
 * @return  Node ID
 */
static inline uint8_t mavlink_msg_fault_get_node_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field error_message from fault message
 *
 * @return  Null terminated Error Message
 */
static inline uint16_t mavlink_msg_fault_get_error_message(const mavlink_message_t* msg, char *error_message)
{
    return _MAV_RETURN_char_array(msg, error_message, 161,  2);
}

/**
 * @brief Decode a fault message into a struct
 *
 * @param msg The message to decode
 * @param fault C-struct to decode the message contents into
 */
static inline void mavlink_msg_fault_decode(const mavlink_message_t* msg, mavlink_fault_t* fault)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    fault->component = mavlink_msg_fault_get_component(msg);
    fault->node_id = mavlink_msg_fault_get_node_id(msg);
    mavlink_msg_fault_get_error_message(msg, fault->error_message);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_FAULT_LEN? msg->len : MAVLINK_MSG_ID_FAULT_LEN;
        memset(fault, 0, MAVLINK_MSG_ID_FAULT_LEN);
    memcpy(fault, _MAV_PAYLOAD(msg), len);
#endif
}
