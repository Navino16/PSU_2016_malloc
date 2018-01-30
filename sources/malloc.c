/*
** malloc for malloc in /home/jaunet_n/Rendu/PSU_2016_malloc
**
** Made by Nathan Jaunet
** Login   <jaunet_n@epitech.net>
**
** Started on  Mon Jan 30 09:24:28 CET 2017 Nathan Jaunet
** Last update Sat Feb 11 13:35:57 2017 Nathan Jaunet
*/

#include "malloc.h"

void		*base = NULL;
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
int		curSpace = 0;

t_block		*find_free_block (t_block **last, size_t size)
{
  t_block	*block;

  block = base;
  while (block && !(block->free && block->size >= size))
    {
      *last = block;
      block = block->next;
    }
  return (block);
}

t_block		*request_space(t_block* last, size_t size)
{
  t_block	*block;
  void		*request;

  if (last)
    block = (void*)(last + 1) + last->size;
  else
    block = sbrk(0);

  if (curSpace < size + STRUCT_SIZE)
    {
      while (curSpace < size + STRUCT_SIZE)
	{
	  request = sbrk(getpagesize());
	  if (request == (void*) -1)
	    return (NULL);
	  curSpace += getpagesize();
	}
    }
  if (last)
    last->next = block;
  block->size = size;
  curSpace -= (size + STRUCT_SIZE);
  block->next = NULL;
  block->free = 0;
  return block;
}

int		malloc2(t_block **last, t_block **block, size_t size)
{
  pthread_mutex_lock(&mutex);
  *last = base;
  *block = find_free_block(last, size);
  if (!*block)
    {
      *block = request_space(*last, size);
      if (!*block)
	return (1);
    }
  else
    (*block)->free = 0;
  pthread_mutex_unlock(&mutex);
  return (0);
}

void		*malloc(size_t size)
{
  t_block	*block;
  t_block	*last;

  if ((int)size < 0)
    return (NULL);
  size = align(size);
  if (!base)
    {
      pthread_mutex_lock(&mutex);
      block = request_space(NULL, size);
      if (!block)
	return (NULL);
      block->free = 0;
      base = block;
      pthread_mutex_unlock(&mutex);
    }
  else
    if (malloc2(&last, &block, size) == 1)
      return (NULL);
  return (block + 1);
}
