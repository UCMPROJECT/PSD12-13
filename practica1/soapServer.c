/* soapServer.c
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

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.10 2012-11-20 02:14:28 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:sendMessage"))
		return soap_serve_ims__sendMessage(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:receiveMessage"))
		return soap_serve_ims__receiveMessage(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:addUser"))
		return soap_serve_ims__addUser(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:userLogin"))
		return soap_serve_ims__userLogin(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:addFriend"))
		return soap_serve_ims__addFriend(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:sendFriendshipRequest"))
		return soap_serve_ims__sendFriendshipRequest(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:getFriendshipRequests"))
		return soap_serve_ims__getFriendshipRequests(soap);
	if (!soap_match_tag(soap, soap->tag, "ims:acceptFriendshipRequest"))
		return soap_serve_ims__acceptFriendshipRequest(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__sendMessage(struct soap *soap)
{	struct ims__sendMessage soap_tmp_ims__sendMessage;
	struct ims__sendMessageResponse soap_tmp_ims__sendMessageResponse;
	int soap_tmp_int;
	soap_default_ims__sendMessageResponse(soap, &soap_tmp_ims__sendMessageResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__sendMessageResponse.result = &soap_tmp_int;
	soap_default_ims__sendMessage(soap, &soap_tmp_ims__sendMessage);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__sendMessage(soap, &soap_tmp_ims__sendMessage, "ims:sendMessage", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__sendMessage(soap, soap_tmp_ims__sendMessage.myMessage, soap_tmp_ims__sendMessageResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__sendMessageResponse(soap, &soap_tmp_ims__sendMessageResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__sendMessageResponse(soap, &soap_tmp_ims__sendMessageResponse, "ims:sendMessageResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__sendMessageResponse(soap, &soap_tmp_ims__sendMessageResponse, "ims:sendMessageResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__receiveMessage(struct soap *soap)
{	struct ims__receiveMessage soap_tmp_ims__receiveMessage;
	struct ims__receiveMessageResponse soap_tmp_ims__receiveMessageResponse;
	struct Message soap_tmp_Message;
	soap_default_ims__receiveMessageResponse(soap, &soap_tmp_ims__receiveMessageResponse);
	soap_default_Message(soap, &soap_tmp_Message);
	soap_tmp_ims__receiveMessageResponse.myMessage = &soap_tmp_Message;
	soap_default_ims__receiveMessage(soap, &soap_tmp_ims__receiveMessage);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__receiveMessage(soap, &soap_tmp_ims__receiveMessage, "ims:receiveMessage", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__receiveMessage(soap, soap_tmp_ims__receiveMessageResponse.myMessage);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__receiveMessageResponse(soap, &soap_tmp_ims__receiveMessageResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__receiveMessageResponse(soap, &soap_tmp_ims__receiveMessageResponse, "ims:receiveMessageResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__receiveMessageResponse(soap, &soap_tmp_ims__receiveMessageResponse, "ims:receiveMessageResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__addUser(struct soap *soap)
{	struct ims__addUser soap_tmp_ims__addUser;
	struct ims__addUserResponse soap_tmp_ims__addUserResponse;
	int soap_tmp_int;
	soap_default_ims__addUserResponse(soap, &soap_tmp_ims__addUserResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__addUserResponse.result = &soap_tmp_int;
	soap_default_ims__addUser(soap, &soap_tmp_ims__addUser);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__addUser(soap, &soap_tmp_ims__addUser, "ims:addUser", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__addUser(soap, soap_tmp_ims__addUser.nick, soap_tmp_ims__addUser.pass, soap_tmp_ims__addUserResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__addUserResponse(soap, &soap_tmp_ims__addUserResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__addUserResponse(soap, &soap_tmp_ims__addUserResponse, "ims:addUserResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__addUserResponse(soap, &soap_tmp_ims__addUserResponse, "ims:addUserResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__userLogin(struct soap *soap)
{	struct ims__userLogin soap_tmp_ims__userLogin;
	struct ims__userLoginResponse soap_tmp_ims__userLoginResponse;
	int soap_tmp_int;
	soap_default_ims__userLoginResponse(soap, &soap_tmp_ims__userLoginResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__userLoginResponse.result = &soap_tmp_int;
	soap_default_ims__userLogin(soap, &soap_tmp_ims__userLogin);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__userLogin(soap, &soap_tmp_ims__userLogin, "ims:userLogin", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__userLogin(soap, soap_tmp_ims__userLogin.nick, soap_tmp_ims__userLogin.pass, soap_tmp_ims__userLoginResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__userLoginResponse(soap, &soap_tmp_ims__userLoginResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__userLoginResponse(soap, &soap_tmp_ims__userLoginResponse, "ims:userLoginResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__userLoginResponse(soap, &soap_tmp_ims__userLoginResponse, "ims:userLoginResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__addFriend(struct soap *soap)
{	struct ims__addFriend soap_tmp_ims__addFriend;
	struct ims__addFriendResponse soap_tmp_ims__addFriendResponse;
	int soap_tmp_int;
	soap_default_ims__addFriendResponse(soap, &soap_tmp_ims__addFriendResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__addFriendResponse.result = &soap_tmp_int;
	soap_default_ims__addFriend(soap, &soap_tmp_ims__addFriend);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__addFriend(soap, &soap_tmp_ims__addFriend, "ims:addFriend", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__addFriend(soap, soap_tmp_ims__addFriend.user, soap_tmp_ims__addFriend.friend_nick, soap_tmp_ims__addFriendResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__addFriendResponse(soap, &soap_tmp_ims__addFriendResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__addFriendResponse(soap, &soap_tmp_ims__addFriendResponse, "ims:addFriendResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__addFriendResponse(soap, &soap_tmp_ims__addFriendResponse, "ims:addFriendResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__sendFriendshipRequest(struct soap *soap)
{	struct ims__sendFriendshipRequest soap_tmp_ims__sendFriendshipRequest;
	struct ims__sendFriendshipRequestResponse soap_tmp_ims__sendFriendshipRequestResponse;
	int soap_tmp_int;
	soap_default_ims__sendFriendshipRequestResponse(soap, &soap_tmp_ims__sendFriendshipRequestResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__sendFriendshipRequestResponse.result = &soap_tmp_int;
	soap_default_ims__sendFriendshipRequest(soap, &soap_tmp_ims__sendFriendshipRequest);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__sendFriendshipRequest(soap, &soap_tmp_ims__sendFriendshipRequest, "ims:sendFriendshipRequest", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__sendFriendshipRequest(soap, soap_tmp_ims__sendFriendshipRequest.user, soap_tmp_ims__sendFriendshipRequest.friend_nick, soap_tmp_ims__sendFriendshipRequestResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__sendFriendshipRequestResponse(soap, &soap_tmp_ims__sendFriendshipRequestResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__sendFriendshipRequestResponse(soap, &soap_tmp_ims__sendFriendshipRequestResponse, "ims:sendFriendshipRequestResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__sendFriendshipRequestResponse(soap, &soap_tmp_ims__sendFriendshipRequestResponse, "ims:sendFriendshipRequestResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__getFriendshipRequests(struct soap *soap)
{	struct ims__getFriendshipRequests soap_tmp_ims__getFriendshipRequests;
	struct ims__getFriendshipRequestsResponse soap_tmp_ims__getFriendshipRequestsResponse;
	int soap_tmp_int;
	soap_default_ims__getFriendshipRequestsResponse(soap, &soap_tmp_ims__getFriendshipRequestsResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__getFriendshipRequestsResponse.result = &soap_tmp_int;
	soap_default_ims__getFriendshipRequests(soap, &soap_tmp_ims__getFriendshipRequests);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__getFriendshipRequests(soap, &soap_tmp_ims__getFriendshipRequests, "ims:getFriendshipRequests", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__getFriendshipRequests(soap, soap_tmp_ims__getFriendshipRequests.user, soap_tmp_ims__getFriendshipRequests.friends, soap_tmp_ims__getFriendshipRequestsResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__getFriendshipRequestsResponse(soap, &soap_tmp_ims__getFriendshipRequestsResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__getFriendshipRequestsResponse(soap, &soap_tmp_ims__getFriendshipRequestsResponse, "ims:getFriendshipRequestsResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__getFriendshipRequestsResponse(soap, &soap_tmp_ims__getFriendshipRequestsResponse, "ims:getFriendshipRequestsResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ims__acceptFriendshipRequest(struct soap *soap)
{	struct ims__acceptFriendshipRequest soap_tmp_ims__acceptFriendshipRequest;
	struct ims__acceptFriendshipRequestResponse soap_tmp_ims__acceptFriendshipRequestResponse;
	int soap_tmp_int;
	soap_default_ims__acceptFriendshipRequestResponse(soap, &soap_tmp_ims__acceptFriendshipRequestResponse);
	soap_default_int(soap, &soap_tmp_int);
	soap_tmp_ims__acceptFriendshipRequestResponse.result = &soap_tmp_int;
	soap_default_ims__acceptFriendshipRequest(soap, &soap_tmp_ims__acceptFriendshipRequest);
	soap->encodingStyle = NULL;
	if (!soap_get_ims__acceptFriendshipRequest(soap, &soap_tmp_ims__acceptFriendshipRequest, "ims:acceptFriendshipRequest", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ims__acceptFriendshipRequest(soap, soap_tmp_ims__acceptFriendshipRequest.user, soap_tmp_ims__acceptFriendshipRequest.friend_nick, soap_tmp_ims__acceptFriendshipRequestResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_ims__acceptFriendshipRequestResponse(soap, &soap_tmp_ims__acceptFriendshipRequestResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ims__acceptFriendshipRequestResponse(soap, &soap_tmp_ims__acceptFriendshipRequestResponse, "ims:acceptFriendshipRequestResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ims__acceptFriendshipRequestResponse(soap, &soap_tmp_ims__acceptFriendshipRequestResponse, "ims:acceptFriendshipRequestResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */
