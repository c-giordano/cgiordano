#ifndef EventFilter_HGCalRawToDigi_HGCalRawDataDefinitions_h
#define EventFilter_HGCalRawToDigi_HGCalRawDataDefinitions_h

namespace hgcal {
  namespace econd {
    enum ToTStatus { ZeroSuppressed = 0x0, noZeroSuppressed_TOASuppressed = 0x1, invalid = 0x2, AutomaticFull = 0x3 };
  }
  enum ECOND_FRAME {
    HEADER_POS = 23,
    HEADER_MASK = 0x1ff,
    PAYLOAD_POS = 14,
    PAYLOAD_MASK = 0x1ff,
    BITP_POS = 13,
    BITE_POS = 12,
    HT_MASK = 0x3,
    HT_POS = 10,
    EBO_MASK = 0x3,
    EBO_POS = 8,
    BITM_POS = 7,
    BITT_POS = 6,
    EHHAM_MASK = 0x3f,
    EHHAM_POS = 0,
    BX_POS = 20,
    BX_MASK = 0xfff,
    L1A_POS = 14,
    L1A_MASK = 0x3f,
    ORBIT_POS = 11,
    ORBIT_MASK = 0x7,
    BITS_POS = 10,
    RR_MASK = 0x3,
    RR_POS = 8,
    EHCRC_MASK = 0xff,
    EHCRC_POS = 0,
    ERXSTAT_POS = 29,
    ERXSTAT_MASK = 0x7,
    ERXHAM_POS = 26,
    ERXHAM_MASK = 0x7,
    ERXFORMAT_POS = 25,
    ERXFORMAT_MASK = 0x1,
    COMMONMODE0_POS = 15,
    COMMONMODE0_MASK = 0x3ff,
    COMMONMODE1_POS = 5,
    COMMONMODE1_MASK = 0x3ff,
    CHMAP32_POS = 0,
    CHMAP32_MASK = 0x1f,
    CHMAP0_POS = 0,
    CHMAP0_MASK = 0xffffffff,
    ERX_E_POS = 4,
    ERX_E_MASK = 1
  };

  enum BACKEND_FRAME {
    CAPTUREBLOCK_RESERVED_MASK = 0x7f,
    CAPTUREBLOCK_RESERVED_POS = 25,
    CAPTUREBLOCK_BC_MASK = 0xfff,
    CAPTUREBLOCK_BC_POS = 13,
    CAPTUREBLOCK_EC_MASK = 0x7f,
    CAPTUREBLOCK_EC_POS = 7,
    CAPTUREBLOCK_OC_MASK = 0x7,
    CAPTUREBLOCK_OC_POS = 4,
    SLINK_BOE_MASK = 0xff,
    SLINK_BOE_POS = 23,
    SLINK_V_MASK = 0xf,
    SLINK_V_POS = 19,
    SLINK_R8_MASK = 0xff,
    SLINK_R8_POS = 11,
    SLINK_GLOBAL_EVENTID_MSB_MASK = 0xfff,
    SLINK_GLOBAL_EVENTID_MSB_POS = 0,
    SLINK_GLOBAL_EVENTID_LSB_MASK = 0xffffffff,
    SLINK_GLOBAL_EVENTID_LSB_POS = 0,
    SLINK_R6_MASK = 0x3f,
    SLINK_R6_POS = 25,
    SLINK_CONTENTID_MASK = 0x3FFFFFF,
    SLINK_CONTENTID_POS = 0,
    SLINK_SOURCEID_MASK = 0xffffffff,
    SLINK_SOURCEID_POS = 0,
    SLINK_EOE_MASK = 0xff,
    SLINK_EOE_POS = 23,
    SLINK_DAQCRC_MASK = 0xffff,
    SLINK_DAQCRC_POS = 7,
    SLINK_TRAILERR_MASK = 0xff,
    SLINK_TRAILERR_POS = 0,
    SLINK_EVLENGTH_MASK = 0xfffff,
    SLINK_EVLENGTH_POS = 11,
    SLINK_BXID_MASK = 0xfff,
    SLINK_BXID_POS = 0,
    SLINK_ORBID_MASK = 0xffffffff,
    SLINK_ORBID_POS = 0,
    SLINK_CRC_MASK = 0xffff,
    SLINK_CRC_POS = 15,
    SLINK_STATUS_MASK = 0xffff,
    SLINK_STATUS_POS = 0,
  };
}  // namespace hgcal

#endif
