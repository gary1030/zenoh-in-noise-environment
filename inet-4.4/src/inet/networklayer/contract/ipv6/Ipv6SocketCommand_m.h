//
// Generated file, do not edit! Created by opp_msgtool 6.0 from inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg.
//

#ifndef __INET_IPV6SOCKETCOMMAND_M_H
#define __INET_IPV6SOCKETCOMMAND_M_H

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

class Ipv6SocketCommandBase;
class Ipv6SocketBindCommand;
class Ipv6SocketConnectCommand;
class Ipv6SocketCloseCommand;
class Ipv6SocketDestroyCommand;
class Ipv6SocketClosedIndication;

}  // namespace inet

#include "inet/common/INETDefs_m.h" // import inet.common.INETDefs

#include "inet/common/Protocol_m.h" // import inet.common.Protocol

#include "inet/networklayer/contract/ipv6/Ipv6Address_m.h" // import inet.networklayer.contract.ipv6.Ipv6Address


namespace inet {

/**
 * Enum generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:14</tt> by opp_msgtool.
 * <pre>
 * enum Ipv6CommandCode
 * {
 *     IPv6_C_BIND = 1;
 *     IPv6_C_CONNECT = 2;
 *     IPv6_C_CLOSE = 3;
 *     IPv6_C_DESTROY = 4;
 * }
 * </pre>
 */
enum Ipv6CommandCode {
    IPv6_C_BIND = 1,
    IPv6_C_CONNECT = 2,
    IPv6_C_CLOSE = 3,
    IPv6_C_DESTROY = 4
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6CommandCode& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6CommandCode& e) { int n; b->unpack(n); e = static_cast<Ipv6CommandCode>(n); }

/**
 * Enum generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:21</tt> by opp_msgtool.
 * <pre>
 * enum Ipv6StatusInd
 * {
 *     IPv6_I_DATA = 0;
 *     IPv6_I_SOCKET_CLOSED = 1;
 * }
 * </pre>
 */
enum Ipv6StatusInd {
    IPv6_I_DATA = 0,
    IPv6_I_SOCKET_CLOSED = 1
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6StatusInd& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6StatusInd& e) { int n; b->unpack(n); e = static_cast<Ipv6StatusInd>(n); }

/**
 * Class generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:27</tt> by opp_msgtool.
 * <pre>
 * class Ipv6SocketCommandBase extends cObject
 * {
 * }
 * </pre>
 */
class INET_API Ipv6SocketCommandBase : public ::omnetpp::cObject
{
  protected:

  private:
    void copy(const Ipv6SocketCommandBase& other);

  protected:
    bool operator==(const Ipv6SocketCommandBase&) = delete;

  public:
    Ipv6SocketCommandBase();
    Ipv6SocketCommandBase(const Ipv6SocketCommandBase& other);
    virtual ~Ipv6SocketCommandBase();
    Ipv6SocketCommandBase& operator=(const Ipv6SocketCommandBase& other);
    virtual Ipv6SocketCommandBase *dup() const override {return new Ipv6SocketCommandBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6SocketCommandBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6SocketCommandBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:31</tt> by opp_msgtool.
 * <pre>
 * class Ipv6SocketBindCommand extends Ipv6SocketCommandBase
 * {
 *     const Protocol *protocol;
 *     Ipv6Address localAddress;
 * }
 * </pre>
 */
class INET_API Ipv6SocketBindCommand : public ::inet::Ipv6SocketCommandBase
{
  protected:
    const Protocol * protocol = nullptr;
    Ipv6Address localAddress;

  private:
    void copy(const Ipv6SocketBindCommand& other);

  protected:
    bool operator==(const Ipv6SocketBindCommand&) = delete;

  public:
    Ipv6SocketBindCommand();
    Ipv6SocketBindCommand(const Ipv6SocketBindCommand& other);
    virtual ~Ipv6SocketBindCommand();
    Ipv6SocketBindCommand& operator=(const Ipv6SocketBindCommand& other);
    virtual Ipv6SocketBindCommand *dup() const override {return new Ipv6SocketBindCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Protocol * getProtocol() const;
    virtual void setProtocol(const Protocol * protocol);

    virtual const Ipv6Address& getLocalAddress() const;
    virtual Ipv6Address& getLocalAddressForUpdate() { return const_cast<Ipv6Address&>(const_cast<Ipv6SocketBindCommand*>(this)->getLocalAddress());}
    virtual void setLocalAddress(const Ipv6Address& localAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6SocketBindCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6SocketBindCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:37</tt> by opp_msgtool.
 * <pre>
 * class Ipv6SocketConnectCommand extends Ipv6SocketCommandBase
 * {
 *     const Protocol *protocol;
 *     Ipv6Address remoteAddress;
 * }
 * </pre>
 */
class INET_API Ipv6SocketConnectCommand : public ::inet::Ipv6SocketCommandBase
{
  protected:
    const Protocol * protocol = nullptr;
    Ipv6Address remoteAddress;

  private:
    void copy(const Ipv6SocketConnectCommand& other);

  protected:
    bool operator==(const Ipv6SocketConnectCommand&) = delete;

  public:
    Ipv6SocketConnectCommand();
    Ipv6SocketConnectCommand(const Ipv6SocketConnectCommand& other);
    virtual ~Ipv6SocketConnectCommand();
    Ipv6SocketConnectCommand& operator=(const Ipv6SocketConnectCommand& other);
    virtual Ipv6SocketConnectCommand *dup() const override {return new Ipv6SocketConnectCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual const Protocol * getProtocol() const;
    virtual void setProtocol(const Protocol * protocol);

    virtual const Ipv6Address& getRemoteAddress() const;
    virtual Ipv6Address& getRemoteAddressForUpdate() { return const_cast<Ipv6Address&>(const_cast<Ipv6SocketConnectCommand*>(this)->getRemoteAddress());}
    virtual void setRemoteAddress(const Ipv6Address& remoteAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6SocketConnectCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6SocketConnectCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:43</tt> by opp_msgtool.
 * <pre>
 * class Ipv6SocketCloseCommand extends Ipv6SocketCommandBase
 * {
 * }
 * </pre>
 */
class INET_API Ipv6SocketCloseCommand : public ::inet::Ipv6SocketCommandBase
{
  protected:

  private:
    void copy(const Ipv6SocketCloseCommand& other);

  protected:
    bool operator==(const Ipv6SocketCloseCommand&) = delete;

  public:
    Ipv6SocketCloseCommand();
    Ipv6SocketCloseCommand(const Ipv6SocketCloseCommand& other);
    virtual ~Ipv6SocketCloseCommand();
    Ipv6SocketCloseCommand& operator=(const Ipv6SocketCloseCommand& other);
    virtual Ipv6SocketCloseCommand *dup() const override {return new Ipv6SocketCloseCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6SocketCloseCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6SocketCloseCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:47</tt> by opp_msgtool.
 * <pre>
 * class Ipv6SocketDestroyCommand extends Ipv6SocketCommandBase
 * {
 * }
 * </pre>
 */
class INET_API Ipv6SocketDestroyCommand : public ::inet::Ipv6SocketCommandBase
{
  protected:

  private:
    void copy(const Ipv6SocketDestroyCommand& other);

  protected:
    bool operator==(const Ipv6SocketDestroyCommand&) = delete;

  public:
    Ipv6SocketDestroyCommand();
    Ipv6SocketDestroyCommand(const Ipv6SocketDestroyCommand& other);
    virtual ~Ipv6SocketDestroyCommand();
    Ipv6SocketDestroyCommand& operator=(const Ipv6SocketDestroyCommand& other);
    virtual Ipv6SocketDestroyCommand *dup() const override {return new Ipv6SocketDestroyCommand(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6SocketDestroyCommand& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6SocketDestroyCommand& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>inet/networklayer/contract/ipv6/Ipv6SocketCommand.msg:51</tt> by opp_msgtool.
 * <pre>
 * class Ipv6SocketClosedIndication extends Ipv6SocketCommandBase
 * {
 * }
 * </pre>
 */
class INET_API Ipv6SocketClosedIndication : public ::inet::Ipv6SocketCommandBase
{
  protected:

  private:
    void copy(const Ipv6SocketClosedIndication& other);

  protected:
    bool operator==(const Ipv6SocketClosedIndication&) = delete;

  public:
    Ipv6SocketClosedIndication();
    Ipv6SocketClosedIndication(const Ipv6SocketClosedIndication& other);
    virtual ~Ipv6SocketClosedIndication();
    Ipv6SocketClosedIndication& operator=(const Ipv6SocketClosedIndication& other);
    virtual Ipv6SocketClosedIndication *dup() const override {return new Ipv6SocketClosedIndication(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Ipv6SocketClosedIndication& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Ipv6SocketClosedIndication& obj) {obj.parsimUnpack(b);}


}  // namespace inet


namespace omnetpp {

template<> inline inet::Ipv6SocketCommandBase *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv6SocketCommandBase*>(ptr.get<cObject>()); }
template<> inline inet::Ipv6SocketBindCommand *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv6SocketBindCommand*>(ptr.get<cObject>()); }
template<> inline inet::Ipv6SocketConnectCommand *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv6SocketConnectCommand*>(ptr.get<cObject>()); }
template<> inline inet::Ipv6SocketCloseCommand *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv6SocketCloseCommand*>(ptr.get<cObject>()); }
template<> inline inet::Ipv6SocketDestroyCommand *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv6SocketDestroyCommand*>(ptr.get<cObject>()); }
template<> inline inet::Ipv6SocketClosedIndication *fromAnyPtr(any_ptr ptr) { return check_and_cast<inet::Ipv6SocketClosedIndication*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __INET_IPV6SOCKETCOMMAND_M_H

