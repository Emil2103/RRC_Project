/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "RRC-ASN1-Module"
 * 	found in "../RRCMessageModule.asn1"
 * 	`asn1c -fcompound-names -gen-PER -pdu=auto`
 */

#include "RRCConnectionSetupRequest.h"

static asn_TYPE_member_t asn_MBR_RRCConnectionSetupRequest_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionSetupRequest, messageHeader),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_RRCMessageHeader,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"messageHeader"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionSetupRequest, mmeUEIdentity),
		(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
		0,
		&asn_DEF_OCTET_STRING,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mmeUEIdentity"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionSetupRequest, sTMSI),
		(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
		0,
		&asn_DEF_OCTET_STRING,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"sTMSI"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionSetupRequest, cellIdentify),
		(ASN_TAG_CLASS_UNIVERSAL | (4 << 2)),
		0,
		&asn_DEF_OCTET_STRING,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cellIdentify"
		},
};
static const ber_tlv_tag_t asn_DEF_RRCConnectionSetupRequest_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RRCConnectionSetupRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 1, 0, 2 }, /* mmeUEIdentity */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 2, -1, 1 }, /* sTMSI */
    { (ASN_TAG_CLASS_UNIVERSAL | (4 << 2)), 3, -2, 0 }, /* cellIdentify */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 0, 0, 0 } /* messageHeader */
};
static asn_SEQUENCE_specifics_t asn_SPC_RRCConnectionSetupRequest_specs_1 = {
	sizeof(struct RRCConnectionSetupRequest),
	offsetof(struct RRCConnectionSetupRequest, _asn_ctx),
	asn_MAP_RRCConnectionSetupRequest_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_RRCConnectionSetupRequest = {
	"RRCConnectionSetupRequest",
	"RRCConnectionSetupRequest",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_RRCConnectionSetupRequest_tags_1,
	sizeof(asn_DEF_RRCConnectionSetupRequest_tags_1)
		/sizeof(asn_DEF_RRCConnectionSetupRequest_tags_1[0]), /* 1 */
	asn_DEF_RRCConnectionSetupRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_RRCConnectionSetupRequest_tags_1)
		/sizeof(asn_DEF_RRCConnectionSetupRequest_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_RRCConnectionSetupRequest_1,
	4,	/* Elements count */
	&asn_SPC_RRCConnectionSetupRequest_specs_1	/* Additional specs */
};

