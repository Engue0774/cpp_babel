/*
** NetworkData.hpp for Server in /home/enguerrand/delivery/Server/NetworkData.hpp
**
** Made by Enguerrand Allamel
** Login   <enguerrand.allamel@epitech.eu>
**
** Started on  mar. sept. 26 23:14:37 2017 Enguerrand Allamel
** Last update mar. sept. 26 23:14:37 2017 Enguerrand Allamel
*/

#ifndef SERVER_NETWORKDATA_HPP
#define SERVER_NETWORKDATA_HPP

#include <array>

namespace babel
{
#pragma pack(push, 1)
  struct NetworkData
  {
    NetworkData() {};
    NetworkData(std::uint32_t code, std::uint32_t size, std::array<char, 2048> data): code(code), size(size), data(data) {};
    std::uint32_t 		code;
    std::uint32_t 		size;
    std::array<char, 2048> 	data;
  };

  struct CLIENT_CONTACT_STRUCT
  {
    char		login[32];
    std::uint8_t	isOnline;
  };

  struct CLIENT_CALL_STRUCT
  {
    char		login[32];
    char 		ip[15];
    std::uint32_t	port;
  };

  struct NetworkDataJoin
  {
    std::uint32_t 	idCall;
  };
#pragma pack(pop)
}

#endif //SERVER_NETWORKDATA_HPP
