/*
** calloc.c for  in /home/jaunet_n/Rendu/tmp
** 
** Made by Nathan Jaunet
** Login   <jaunet_n@epitech.net>
** 
** Started on  Sat Feb 11 13:19:50 2017 Nathan Jaunet
** Last update Sat Feb 11 13:35:26 2017 Nathan Jaunet
*/

#include "malloc.h"

void	*calloc(size_t nmemb, size_t elsize)
{
  size_t size;
  void *ptr;

  if ((int)nmemb < 0 || (int)elsize < 0)
    return (NULL);
  size = nmemb * elsize;
  ptr = malloc(size);
  memset(ptr, 0, size);
  return (ptr);
}
