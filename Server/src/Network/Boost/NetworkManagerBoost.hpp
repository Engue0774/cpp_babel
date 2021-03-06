/*
** NetworkManagerBoost.hpp for Server in /home/enguerrand/delivery/Server/NetworkManagerBoost.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  dim. sept. 24 11:25:19 2017 Enguerrand Allamel
** Last update dim. sept. 24 11:25:19 2017 Enguerrand Allamel
*/

#ifndef SERVER_NETWORKMANAGERBOOST_HPP
#define SERVER_NETWORKMANAGERBOOST_HPP

#include <unordered_map>
#include "Network/Interfaces/INetworkManager.hpp"
#include "NetworkTcpServerBoost.hpp"

namespace babel
{
  class Server;

  class NetworkManagerBoost : public INetworkManager
  {
   protected:
    Server		&_server;
    unsigned int	_port;

    NetworkTcpServerBoost								_tcpServer;
    std::unordered_map<size_t, TunnelInfo>						_tunnelInfo;
    std::unordered_map<size_t, NetworkTcpServerTunnelBoost::pointer>			_tunnelList;
   public:
    NetworkManagerBoost(Server &server, unsigned int port);
    ~NetworkManagerBoost();
   public:
    virtual void acceptClient();


    virtual bool write(size_t tunnelId, NetworkData data);
    virtual bool write(std::string login, NetworkData data);

    virtual bool writeForAll(NetworkData data);

    virtual TunnelInfo & getTunnelInfoByTunnelId(const size_t tunnelId);

    virtual void setIpForTunnelId(size_t tunnelId, const std::string & ip);

    virtual void closeTunnel(size_t tunnelId);

    virtual const size_t getTunnelIdByLogin(const std::string login);

   public:
    void addTunnel(NetworkTcpServerTunnelBoost::pointer tunnel);
  };
}

#endif //SERVER_NETWORKMANAGERBOOST_HPP
