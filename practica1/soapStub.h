/* soapStub.h
   Generated by gSOAP 2.8.10 from ims.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#define IMS_MAX_MSG_SIZE 256
#define MAXFRIENDS 100
#include "stdsoap2.h"
#if GSOAP_VERSION != 20810
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_Message
#define SOAP_TYPE_Message (8)
/* Message */
struct Message
{
	char *name;	/* optional element of type xsd:string */
	char *msg;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE__Struct_1
#define SOAP_TYPE__Struct_1 (10)
/* Struct-1 */
struct _Struct_1
{
	char *data[100];	/* required element of type Array100Ofstring */
};
#endif

#ifndef SOAP_TYPE__Struct_2
#define SOAP_TYPE__Struct_2 (12)
/* Struct-2 */
struct _Struct_2
{
	char *str;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__sendMessageResponse
#define SOAP_TYPE_ims__sendMessageResponse (16)
/* ims:sendMessageResponse */
struct ims__sendMessageResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__sendMessage
#define SOAP_TYPE_ims__sendMessage (17)
/* ims:sendMessage */
struct ims__sendMessage
{
	struct Message myMessage;	/* required element of type Message */
};
#endif

#ifndef SOAP_TYPE_ims__receiveMessageResponse
#define SOAP_TYPE_ims__receiveMessageResponse (20)
/* ims:receiveMessageResponse */
struct ims__receiveMessageResponse
{
	struct Message *myMessage;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type Message */
};
#endif

#ifndef SOAP_TYPE_ims__receiveMessage
#define SOAP_TYPE_ims__receiveMessage (21)
/* ims:receiveMessage */
struct ims__receiveMessage
{
#ifdef WITH_NOEMPTYSTRUCT
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#ifndef SOAP_TYPE_ims__addUserResponse
#define SOAP_TYPE_ims__addUserResponse (23)
/* ims:addUserResponse */
struct ims__addUserResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__addUser
#define SOAP_TYPE_ims__addUser (24)
/* ims:addUser */
struct ims__addUser
{
	char *nick;	/* optional element of type xsd:string */
	char *pass;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__userLoginResponse
#define SOAP_TYPE_ims__userLoginResponse (26)
/* ims:userLoginResponse */
struct ims__userLoginResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__userLogin
#define SOAP_TYPE_ims__userLogin (27)
/* ims:userLogin */
struct ims__userLogin
{
	char *nick;	/* optional element of type xsd:string */
	char *pass;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__addFriendResponse
#define SOAP_TYPE_ims__addFriendResponse (29)
/* ims:addFriendResponse */
struct ims__addFriendResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__addFriend
#define SOAP_TYPE_ims__addFriend (30)
/* ims:addFriend */
struct ims__addFriend
{
	char *user;	/* optional element of type xsd:string */
	char *friend_nick;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__sendFriendshipRequestResponse
#define SOAP_TYPE_ims__sendFriendshipRequestResponse (32)
/* ims:sendFriendshipRequestResponse */
struct ims__sendFriendshipRequestResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__sendFriendshipRequest
#define SOAP_TYPE_ims__sendFriendshipRequest (33)
/* ims:sendFriendshipRequest */
struct ims__sendFriendshipRequest
{
	char *user;	/* optional element of type xsd:string */
	char *friend_nick;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__getFriendshipRequestsResponse
#define SOAP_TYPE_ims__getFriendshipRequestsResponse (36)
/* ims:getFriendshipRequestsResponse */
struct ims__getFriendshipRequestsResponse
{
	struct _Struct_1 *friends;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type Char-vector */
};
#endif

#ifndef SOAP_TYPE_ims__getFriendshipRequests
#define SOAP_TYPE_ims__getFriendshipRequests (37)
/* ims:getFriendshipRequests */
struct ims__getFriendshipRequests
{
	char *user;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__haveFriendshipRequestResponse
#define SOAP_TYPE_ims__haveFriendshipRequestResponse (39)
/* ims:haveFriendshipRequestResponse */
struct ims__haveFriendshipRequestResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__haveFriendshipRequest
#define SOAP_TYPE_ims__haveFriendshipRequest (40)
/* ims:haveFriendshipRequest */
struct ims__haveFriendshipRequest
{
	char *user;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__getFriendshipRequestResponse
#define SOAP_TYPE_ims__getFriendshipRequestResponse (43)
/* ims:getFriendshipRequestResponse */
struct ims__getFriendshipRequestResponse
{
	struct _Struct_2 *friend_nick;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type String */
};
#endif

#ifndef SOAP_TYPE_ims__getFriendshipRequest
#define SOAP_TYPE_ims__getFriendshipRequest (44)
/* ims:getFriendshipRequest */
struct ims__getFriendshipRequest
{
	char *user;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__acceptFriendshipRequestResponse
#define SOAP_TYPE_ims__acceptFriendshipRequestResponse (46)
/* ims:acceptFriendshipRequestResponse */
struct ims__acceptFriendshipRequestResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__acceptFriendshipRequest
#define SOAP_TYPE_ims__acceptFriendshipRequest (47)
/* ims:acceptFriendshipRequest */
struct ims__acceptFriendshipRequest
{
	char *user;	/* optional element of type xsd:string */
	char *friend_nick;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__rejectFriendshipRequestResponse
#define SOAP_TYPE_ims__rejectFriendshipRequestResponse (49)
/* ims:rejectFriendshipRequestResponse */
struct ims__rejectFriendshipRequestResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__rejectFriendshipRequest
#define SOAP_TYPE_ims__rejectFriendshipRequest (50)
/* ims:rejectFriendshipRequest */
struct ims__rejectFriendshipRequest
{
	char *user;	/* optional element of type xsd:string */
	char *friend_nick;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__getFriendsResponse
#define SOAP_TYPE_ims__getFriendsResponse (52)
/* ims:getFriendsResponse */
struct ims__getFriendsResponse
{
	struct _Struct_1 *friends;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type Char-vector */
};
#endif

#ifndef SOAP_TYPE_ims__getFriends
#define SOAP_TYPE_ims__getFriends (53)
/* ims:getFriends */
struct ims__getFriends
{
	char *user;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_ims__haveFriendsResponse
#define SOAP_TYPE_ims__haveFriendsResponse (55)
/* ims:haveFriendsResponse */
struct ims__haveFriendsResponse
{
	int *result;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type xsd:int */
};
#endif

#ifndef SOAP_TYPE_ims__haveFriends
#define SOAP_TYPE_ims__haveFriends (56)
/* ims:haveFriends */
struct ims__haveFriends
{
	char *user;	/* optional element of type xsd:string */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (57)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (58)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (60)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (63)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (64)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE_xsd__string
#define SOAP_TYPE_xsd__string (7)
typedef char *xsd__string;
#endif

#ifndef SOAP_TYPE_Char_vector
#define SOAP_TYPE_Char_vector (11)
typedef struct _Struct_1 Char_vector;
#endif

#ifndef SOAP_TYPE_String
#define SOAP_TYPE_String (13)
typedef struct _Struct_2 String;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 ims__sendMessage(struct soap*, struct Message myMessage, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__receiveMessage(struct soap*, struct Message *myMessage);

SOAP_FMAC5 int SOAP_FMAC6 ims__addUser(struct soap*, char *nick, char *pass, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__userLogin(struct soap*, char *nick, char *pass, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__addFriend(struct soap*, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__sendFriendshipRequest(struct soap*, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__getFriendshipRequests(struct soap*, char *user, struct _Struct_1 *friends);

SOAP_FMAC5 int SOAP_FMAC6 ims__haveFriendshipRequest(struct soap*, char *user, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__getFriendshipRequest(struct soap*, char *user, struct _Struct_2 *friend_nick);

SOAP_FMAC5 int SOAP_FMAC6 ims__acceptFriendshipRequest(struct soap*, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__rejectFriendshipRequest(struct soap*, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 ims__getFriends(struct soap*, char *user, struct _Struct_1 *friends);

SOAP_FMAC5 int SOAP_FMAC6 ims__haveFriends(struct soap*, char *user, int *result);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__sendMessage(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__receiveMessage(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__addUser(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__userLogin(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__addFriend(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__sendFriendshipRequest(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__getFriendshipRequests(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__haveFriendshipRequest(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__getFriendshipRequest(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__acceptFriendshipRequest(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__rejectFriendshipRequest(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__getFriends(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__haveFriends(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__sendMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct Message myMessage, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__receiveMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct Message *myMessage);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__addUser(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *nick, char *pass, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__userLogin(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *nick, char *pass, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__addFriend(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__sendFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getFriendshipRequests(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_1 *friends);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__haveFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_2 *friend_nick);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__acceptFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__rejectFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getFriends(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_1 *friends);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__haveFriends(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, int *result);

#ifdef __cplusplus
}
#endif

#endif

/* End of soapStub.h */
