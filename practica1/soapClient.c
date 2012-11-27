/* soapClient.c
   Generated by gSOAP 2.8.10 from ims.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.10 2012-11-27 14:36:18 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__sendMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_1 myMessage, int *error)
{	struct ims__sendMessage soap_tmp_ims__sendMessage;
	struct ims__sendMessageResponse *soap_tmp_ims__sendMessageResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__sendMessage.user = user;
	soap_tmp_ims__sendMessage.myMessage = myMessage;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__sendMessage(soap, &soap_tmp_ims__sendMessage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__sendMessage(soap, &soap_tmp_ims__sendMessage, "ims:sendMessage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__sendMessage(soap, &soap_tmp_ims__sendMessage, "ims:sendMessage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!error)
		return soap_closesock(soap);
	soap_default_int(soap, error);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__sendMessageResponse = soap_get_ims__sendMessageResponse(soap, NULL, "ims:sendMessageResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (error && soap_tmp_ims__sendMessageResponse->error)
		*error = *soap_tmp_ims__sendMessageResponse->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__receiveMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, int num, char *friend_nick, struct _Struct_1 *myMessage)
{	struct ims__receiveMessage soap_tmp_ims__receiveMessage;
	struct ims__receiveMessageResponse *soap_tmp_ims__receiveMessageResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__receiveMessage.user = user;
	soap_tmp_ims__receiveMessage.num = num;
	soap_tmp_ims__receiveMessage.friend_nick = friend_nick;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__receiveMessage(soap, &soap_tmp_ims__receiveMessage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__receiveMessage(soap, &soap_tmp_ims__receiveMessage, "ims:receiveMessage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__receiveMessage(soap, &soap_tmp_ims__receiveMessage, "ims:receiveMessage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!myMessage)
		return soap_closesock(soap);
	soap_default_Message(soap, myMessage);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__receiveMessageResponse = soap_get_ims__receiveMessageResponse(soap, NULL, "ims:receiveMessageResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (myMessage && soap_tmp_ims__receiveMessageResponse->myMessage)
		*myMessage = *soap_tmp_ims__receiveMessageResponse->myMessage;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getLastMessage(struct soap *soap, const char *soap_endpoint, const char *soap_action, struct _Struct_1 *myMessage)
{	struct ims__getLastMessage soap_tmp_ims__getLastMessage;
	struct ims__getLastMessageResponse *soap_tmp_ims__getLastMessageResponse;
	soap->encodingStyle = NULL;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__getLastMessage(soap, &soap_tmp_ims__getLastMessage);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__getLastMessage(soap, &soap_tmp_ims__getLastMessage, "ims:getLastMessage", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__getLastMessage(soap, &soap_tmp_ims__getLastMessage, "ims:getLastMessage", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!myMessage)
		return soap_closesock(soap);
	soap_default_Message(soap, myMessage);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__getLastMessageResponse = soap_get_ims__getLastMessageResponse(soap, NULL, "ims:getLastMessageResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (myMessage && soap_tmp_ims__getLastMessageResponse->myMessage)
		*myMessage = *soap_tmp_ims__getLastMessageResponse->myMessage;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__addUser(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *nick, char *pass, int *error)
{	struct ims__addUser soap_tmp_ims__addUser;
	struct ims__addUserResponse *soap_tmp_ims__addUserResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__addUser.nick = nick;
	soap_tmp_ims__addUser.pass = pass;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__addUser(soap, &soap_tmp_ims__addUser);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__addUser(soap, &soap_tmp_ims__addUser, "ims:addUser", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__addUser(soap, &soap_tmp_ims__addUser, "ims:addUser", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!error)
		return soap_closesock(soap);
	soap_default_int(soap, error);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__addUserResponse = soap_get_ims__addUserResponse(soap, NULL, "ims:addUserResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (error && soap_tmp_ims__addUserResponse->error)
		*error = *soap_tmp_ims__addUserResponse->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__userLogin(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *nick, char *pass, int *error)
{	struct ims__userLogin soap_tmp_ims__userLogin;
	struct ims__userLoginResponse *soap_tmp_ims__userLoginResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__userLogin.nick = nick;
	soap_tmp_ims__userLogin.pass = pass;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__userLogin(soap, &soap_tmp_ims__userLogin);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__userLogin(soap, &soap_tmp_ims__userLogin, "ims:userLogin", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__userLogin(soap, &soap_tmp_ims__userLogin, "ims:userLogin", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!error)
		return soap_closesock(soap);
	soap_default_int(soap, error);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__userLoginResponse = soap_get_ims__userLoginResponse(soap, NULL, "ims:userLoginResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (error && soap_tmp_ims__userLoginResponse->error)
		*error = *soap_tmp_ims__userLoginResponse->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__userLogout(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *nick, char *pass, int *error)
{	struct ims__userLogout soap_tmp_ims__userLogout;
	struct ims__userLogoutResponse *soap_tmp_ims__userLogoutResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__userLogout.nick = nick;
	soap_tmp_ims__userLogout.pass = pass;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__userLogout(soap, &soap_tmp_ims__userLogout);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__userLogout(soap, &soap_tmp_ims__userLogout, "ims:userLogout", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__userLogout(soap, &soap_tmp_ims__userLogout, "ims:userLogout", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!error)
		return soap_closesock(soap);
	soap_default_int(soap, error);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__userLogoutResponse = soap_get_ims__userLogoutResponse(soap, NULL, "ims:userLogoutResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (error && soap_tmp_ims__userLogoutResponse->error)
		*error = *soap_tmp_ims__userLogoutResponse->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__addFriend(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *error)
{	struct ims__addFriend soap_tmp_ims__addFriend;
	struct ims__addFriendResponse *soap_tmp_ims__addFriendResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__addFriend.user = user;
	soap_tmp_ims__addFriend.friend_nick = friend_nick;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__addFriend(soap, &soap_tmp_ims__addFriend);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__addFriend(soap, &soap_tmp_ims__addFriend, "ims:addFriend", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__addFriend(soap, &soap_tmp_ims__addFriend, "ims:addFriend", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!error)
		return soap_closesock(soap);
	soap_default_int(soap, error);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__addFriendResponse = soap_get_ims__addFriendResponse(soap, NULL, "ims:addFriendResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (error && soap_tmp_ims__addFriendResponse->error)
		*error = *soap_tmp_ims__addFriendResponse->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__sendFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *error)
{	struct ims__sendFriendshipRequest soap_tmp_ims__sendFriendshipRequest;
	struct ims__sendFriendshipRequestResponse *soap_tmp_ims__sendFriendshipRequestResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__sendFriendshipRequest.user = user;
	soap_tmp_ims__sendFriendshipRequest.friend_nick = friend_nick;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__sendFriendshipRequest(soap, &soap_tmp_ims__sendFriendshipRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__sendFriendshipRequest(soap, &soap_tmp_ims__sendFriendshipRequest, "ims:sendFriendshipRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__sendFriendshipRequest(soap, &soap_tmp_ims__sendFriendshipRequest, "ims:sendFriendshipRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!error)
		return soap_closesock(soap);
	soap_default_int(soap, error);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__sendFriendshipRequestResponse = soap_get_ims__sendFriendshipRequestResponse(soap, NULL, "ims:sendFriendshipRequestResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (error && soap_tmp_ims__sendFriendshipRequestResponse->error)
		*error = *soap_tmp_ims__sendFriendshipRequestResponse->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getFriendshipRequests(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_2 *friends)
{	struct ims__getFriendshipRequests soap_tmp_ims__getFriendshipRequests;
	struct ims__getFriendshipRequestsResponse *soap_tmp_ims__getFriendshipRequestsResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__getFriendshipRequests.user = user;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__getFriendshipRequests(soap, &soap_tmp_ims__getFriendshipRequests);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__getFriendshipRequests(soap, &soap_tmp_ims__getFriendshipRequests, "ims:getFriendshipRequests", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__getFriendshipRequests(soap, &soap_tmp_ims__getFriendshipRequests, "ims:getFriendshipRequests", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!friends)
		return soap_closesock(soap);
	soap_default_Char_vector(soap, friends);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__getFriendshipRequestsResponse = soap_get_ims__getFriendshipRequestsResponse(soap, NULL, "ims:getFriendshipRequestsResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (friends && soap_tmp_ims__getFriendshipRequestsResponse->friends)
		*friends = *soap_tmp_ims__getFriendshipRequestsResponse->friends;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__haveFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, int *result)
{	struct ims__haveFriendshipRequest soap_tmp_ims__haveFriendshipRequest;
	struct ims__haveFriendshipRequestResponse *soap_tmp_ims__haveFriendshipRequestResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__haveFriendshipRequest.user = user;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__haveFriendshipRequest(soap, &soap_tmp_ims__haveFriendshipRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__haveFriendshipRequest(soap, &soap_tmp_ims__haveFriendshipRequest, "ims:haveFriendshipRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__haveFriendshipRequest(soap, &soap_tmp_ims__haveFriendshipRequest, "ims:haveFriendshipRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_int(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__haveFriendshipRequestResponse = soap_get_ims__haveFriendshipRequestResponse(soap, NULL, "ims:haveFriendshipRequestResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ims__haveFriendshipRequestResponse->result)
		*result = *soap_tmp_ims__haveFriendshipRequestResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_3 *friend_nick)
{	struct ims__getFriendshipRequest soap_tmp_ims__getFriendshipRequest;
	struct ims__getFriendshipRequestResponse *soap_tmp_ims__getFriendshipRequestResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__getFriendshipRequest.user = user;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__getFriendshipRequest(soap, &soap_tmp_ims__getFriendshipRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__getFriendshipRequest(soap, &soap_tmp_ims__getFriendshipRequest, "ims:getFriendshipRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__getFriendshipRequest(soap, &soap_tmp_ims__getFriendshipRequest, "ims:getFriendshipRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!friend_nick)
		return soap_closesock(soap);
	soap_default_String(soap, friend_nick);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__getFriendshipRequestResponse = soap_get_ims__getFriendshipRequestResponse(soap, NULL, "ims:getFriendshipRequestResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (friend_nick && soap_tmp_ims__getFriendshipRequestResponse->friend_nick)
		*friend_nick = *soap_tmp_ims__getFriendshipRequestResponse->friend_nick;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__acceptFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *result)
{	struct ims__acceptFriendshipRequest soap_tmp_ims__acceptFriendshipRequest;
	struct ims__acceptFriendshipRequestResponse *soap_tmp_ims__acceptFriendshipRequestResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__acceptFriendshipRequest.user = user;
	soap_tmp_ims__acceptFriendshipRequest.friend_nick = friend_nick;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__acceptFriendshipRequest(soap, &soap_tmp_ims__acceptFriendshipRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__acceptFriendshipRequest(soap, &soap_tmp_ims__acceptFriendshipRequest, "ims:acceptFriendshipRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__acceptFriendshipRequest(soap, &soap_tmp_ims__acceptFriendshipRequest, "ims:acceptFriendshipRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_int(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__acceptFriendshipRequestResponse = soap_get_ims__acceptFriendshipRequestResponse(soap, NULL, "ims:acceptFriendshipRequestResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ims__acceptFriendshipRequestResponse->result)
		*result = *soap_tmp_ims__acceptFriendshipRequestResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__rejectFriendshipRequest(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, char *friend_nick, int *result)
{	struct ims__rejectFriendshipRequest soap_tmp_ims__rejectFriendshipRequest;
	struct ims__rejectFriendshipRequestResponse *soap_tmp_ims__rejectFriendshipRequestResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__rejectFriendshipRequest.user = user;
	soap_tmp_ims__rejectFriendshipRequest.friend_nick = friend_nick;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__rejectFriendshipRequest(soap, &soap_tmp_ims__rejectFriendshipRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__rejectFriendshipRequest(soap, &soap_tmp_ims__rejectFriendshipRequest, "ims:rejectFriendshipRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__rejectFriendshipRequest(soap, &soap_tmp_ims__rejectFriendshipRequest, "ims:rejectFriendshipRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_int(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__rejectFriendshipRequestResponse = soap_get_ims__rejectFriendshipRequestResponse(soap, NULL, "ims:rejectFriendshipRequestResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ims__rejectFriendshipRequestResponse->result)
		*result = *soap_tmp_ims__rejectFriendshipRequestResponse->result;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__getFriends(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, struct _Struct_2 *friends)
{	struct ims__getFriends soap_tmp_ims__getFriends;
	struct ims__getFriendsResponse *soap_tmp_ims__getFriendsResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__getFriends.user = user;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__getFriends(soap, &soap_tmp_ims__getFriends);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__getFriends(soap, &soap_tmp_ims__getFriends, "ims:getFriends", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__getFriends(soap, &soap_tmp_ims__getFriends, "ims:getFriends", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!friends)
		return soap_closesock(soap);
	soap_default_Char_vector(soap, friends);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__getFriendsResponse = soap_get_ims__getFriendsResponse(soap, NULL, "ims:getFriendsResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (friends && soap_tmp_ims__getFriendsResponse->friends)
		*friends = *soap_tmp_ims__getFriendsResponse->friends;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ims__haveFriends(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *user, int *result)
{	struct ims__haveFriends soap_tmp_ims__haveFriends;
	struct ims__haveFriendsResponse *soap_tmp_ims__haveFriendsResponse;
	soap->encodingStyle = NULL;
	soap_tmp_ims__haveFriends.user = user;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ims__haveFriends(soap, &soap_tmp_ims__haveFriends);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__haveFriends(soap, &soap_tmp_ims__haveFriends, "ims:haveFriends", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__haveFriends(soap, &soap_tmp_ims__haveFriends, "ims:haveFriends", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_int(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ims__haveFriendsResponse = soap_get_ims__haveFriendsResponse(soap, NULL, "ims:haveFriendsResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ims__haveFriendsResponse->result)
		*result = *soap_tmp_ims__haveFriendsResponse->result;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */
