#include "udp_client.h"
#include <pthread.h>
#include "data.h"
#include "window.h"
#include <vector>

typedef struct 
{
  udp_client* clientp;
  window* winp;
  std::string nick_name;
  std::string school;
}client_info_t;

client_info_t cw;

std::vector<std::string> friends; 
static void add_user(std::string& f);

void Usage(std::string proc)
{
  std::cout << proc << "server_ip server_port" << std::endl;
}

void *run_header(void* arg)
{
  client_info_t* cwp = (client_info_t*)arg;
  window* wp = cwp->winp;

  wp->draw_header();
  std::string title = "Chat System!";
  int i = 1;
  int y, x;
  int dir = 0;
  while (1)
  {
    //解决重影
    wp->draw_header();
    getmaxyx(wp->get_header(), y, x);
    wp->put_string_to_window(wp->get_header(), y / 2, i, title);
    if (i >= x - title.size() - 3)
    {
      //左 <- 右
      dir = 1;
    }
    if (i <= 4)
    {
      dir = 0;
    }
    if (dir == 0)
    {
      i++;
    }
    else 
    {
      i--;
    }
    i %= (x - title.size());
    usleep(100000);
  }

  return NULL;
}

void *run_out_flist(void* arg)
{
  client_info_t* cwp = (client_info_t*)arg;
  window* wp = cwp->winp;
  udp_client* cp = cwp->clientp;

  wp->draw_ouput();
  wp->draw_flist();
  int y, x;
  int i = 1;
  std::string out_string;
  std::string show_string;
  data d;
  
  while (1)
  {
    cp->recv_data(out_string);
    d.unserialize(out_string);
    show_string = d.nick_name;
    show_string += "-";
    show_string += d.school;

    add_user(show_string);


    show_string += "#";
    show_string += d.message;
    getmaxyx(wp->get_output(), y, x);
    wp->put_string_to_window(wp->get_output(), i++, 2, show_string);
    if (i > y - 1)
    {
      i = 1;
      wp->draw_ouput();
      sleep(1);
    }

    //flist
    
  }
}

void *run_input(void* arg)
{
  client_info_t* cwp = (client_info_t*)arg;
  window* wp = cwp->winp;
  udp_client* cp = cwp->clientp;
  
  wp->draw_input();
  std::string tips = "Please Enter# ";
  std::string str;
  data d;
  std::string out_string;
  while (1)
  {
    wp->put_string_to_window(wp->get_input(), 1, 2, tips);
    wp->get_string_from_window(wp->get_input(), str);
    d.nick_name = cwp->nick_name;
    d.school = cwp->school;
    d.message = str;
    d.type = "None";
    d.serialize(out_string);
    cp->send_data(out_string);
    
    wp->draw_input();
  }
}

// ./chatCLient 192.168.2.1 8080
int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    Usage(argv[0]);
    return 1;
  }
  
  std::cout << "Please Enter You Nick Name# ";
  std::cin >> cw.nick_name;
  std::cout << "Please Enter Your School# ";
  std::cin >> cw.school;

  udp_client cli(argv[1], atoi(argv[2]));
  cli.init_client();
  window w;

  cw.clientp = &cli;
  cw.winp = &w;
  pthread_t header, output_flist, input;
  pthread_create(&header, NULL, run_header, (void*)&cw);
  pthread_create(&output_flist, NULL, run_out_flist, (void*)&cw);
  pthread_create(&input, NULL, run_input, (void*)&cw);

  pthread_join(header, NULL);
  pthread_join(output_flist, NULL);
  pthread_join(input, NULL);
  return 0;
}
