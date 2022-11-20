//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/probabilistic/ProbabilisticBroadcastHeader.msg.
//

#ifndef __INET_PROBABILISTICBROADCASTHEADER_M_H
#define __INET_PROBABILISTICBROADCASTHEADER_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef INET_API
#  if defined(INET_EXPORT)
#    define INET_API  OPP_DLLEXPORT
#  elif defined(INET_IMPORT)
#    define INET_API  OPP_DLLIMPORT
#  else
#    define INET_API
#  endif
#endif


namespace inet {

class ProbabilisticBroadcastHeader;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Units_m.h" // import inet.common.Units

#include "inet/networklayer/common/IpProtocolId_m.h" // import inet.networklayer.common.IpProtocolId

#include "inet/networklayer/contract/NetworkHeaderBase_m.h" // import inet.networklayer.contract.NetworkHeaderBase

// cplusplus {{
#include "inet/common/ProtocolGroup.h"
// }}


namespace inet {

/**
 * Class generated from <tt>inet/networklayer/probabilistic/ProbabilisticBroadcastHeader.msg:19</tt> by opp_msgtool.
 * <pre>
 * class ProbabilisticBroadcastHeader extends NetworkHeaderBase
 * {
 *     L3Address srcAddr;
 *     L3Address destAddr;
 *     long id;    // Unique message ID ~ f(node address, unique number in node scope).
 *     int nbHops;
 *     IpProtocolId protocolId;
 *     simtime_t appTtl;   // Message time-to-live set by application.
 *     L3Address initialSrcAddr;
 *     L3Address finalDestAddr;
 *     B payloadLengthField;
 * }
 * </pre>
 */
class INET_API ProbabilisticBroadcastHeader : public ::inet::NetworkHeaderBase
{
  protected:
    L3Address srcAddr;
    L3Address destAddr;
    long id = 0;
    int nbHops = 0;
    IpProtocolId protocolId = static_cast<inet::IpProtocolId>(-1);
    ::omnetpp::simtime_t appTtl = SIMTIME_ZERO;
    L3Address initialSrcAddr;
    L3Address finalDestAddr;
    B payloadLengthField = B(-1);

  private:
    void copy(const ProbabilisticBroadcastHeader& other);

  protected:
    bool operator==(const ProbabilisticBroadcastHeader&) = delete;

  public:
    ProbabilisticBroadcastHeader();
    ProbabilisticBroadcastHeader(const ProbabilisticBroadcastHeader& other);
    virtual ~ProbabilisticBroadcastHeader();
    ProbabilisticBroadcastHeader& operator=(const ProbabilisticBroadcastHeader& other);
    virtual ProbabilisticBroadcastHeader *dup() const override {return new ProbabilisticBroadcastHeader(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const L3Address& getSrcAddr() const;
    virtual L3Address& getSrcAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<ProbabilisticBroadcastHeader*>(this)->getSrcAddr());}
    virtual void setSrcAddr(const L3Address& srcAddr);

    virtual const L3Address& getDestAddr() const;
    virtual L3Address& getDestAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<ProbabilisticBroadcastHeader*>(this)->getDestAddr());}
    virtual void setDestAddr(const L3Address& destAddr);

    virtual long getId() const;
    virtual void setId(long id);

    virtual int getNbHops() const;
    virtual void setNbHops(int nbHops);

    virtual IpProtocolId getProtocolId() const;
    virtual void setProtocolId(IpProtocolId protocolId);

    virtual ::omnetpp::simtime_t getAppTtl() const;
    virtual void setAppTtl(::omnetpp::simtime_t appTtl);

    virtual const L3Address& getInitialSrcAddr() const;
    virtual L3Address& getInitialSrcAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<ProbabilisticBroadcastHeader*>(this)->getInitialSrcAddr());}
    virtual void setInitialSrcAddr(const L3Address& initialSrcAddr);

    virtual const L3Address& getFinalDestAddr() const;
    virtual L3Address& getFinalDestAddrForUpdate() { handleChange();return const_cast<L3Address&>(const_cast<ProbabilisticBroadcastHeader*>(this)->getFinalDestAddr());}
    virtual void setFinalDestAddr(const L3Address& finalDestAddr);

    virtual B getPayloadLengthField() const;
    virtual void setPayloadLengthField(B payloadLengthField);


  public:
    virtual L3Address getSourceAddress() const override { return getSrcAddr(); }
    virtual void setSourceAddress(const L3Address& address) override { setSrcAddr(address); }
    virtual L3Address getDestinationAddress() const override { return getDestAddr(); }
    virtual void setDestinationAddress(const L3Address& address) override { setDestAddr(address); }
    virtual const Protocol *getProtocol() const override { return ProtocolGroup::ipprotocol.findProtocol(getProtocolId()); }
    virtual void setProtocol(const Protocol *protocol) override { setProtocolId(static_cast<IpProtocolId>(ProtocolGroup::ipprotocol.getProtocolNumber(protocol))); }
    virtual bool isFragment() const override { return false; }
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ProbabilisticBroadcastHeader& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ProbabilisticBroadcastHeader& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::ProbabilisticBroadcastHeader *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::ProbabilisticBroadcastHeader*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_PROBABILISTICBROADCASTHEADER_M_H

