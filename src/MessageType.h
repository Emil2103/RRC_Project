/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RRC-ASN1-Module"
 * 	found in "../RRCMessageModule.asn1"
 * 	`asn1c -fcompound-names -gen-PER -pdu=auto`
 */

#ifndef	_MessageType_H_
#define	_MessageType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MessageType {
	MessageType_rrcConnectionSetupRequest	= 0,
	MessageType_rrcConnectionSetupComplete	= 1
} e_MessageType;

/* MessageType */
typedef long	 MessageType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MessageType;
asn_struct_free_f MessageType_free;
asn_struct_print_f MessageType_print;
asn_constr_check_f MessageType_constraint;
ber_type_decoder_f MessageType_decode_ber;
der_type_encoder_f MessageType_encode_der;
xer_type_decoder_f MessageType_decode_xer;
xer_type_encoder_f MessageType_encode_xer;
per_type_decoder_f MessageType_decode_uper;
per_type_encoder_f MessageType_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _MessageType_H_ */
#include <asn_internal.h>
