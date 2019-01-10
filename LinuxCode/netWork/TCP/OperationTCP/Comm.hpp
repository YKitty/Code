#pragma once 

#include <iostream>

typedef struct request
{
  double x;
  double y;
  int cal;//01234 +-*/%
}request;


typedef struct response
{
  double result;
  int status;//0:OK 1:num/0  2:other question
}response;
