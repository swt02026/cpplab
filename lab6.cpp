#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
int main()
{

    int sock = socket(AF_INET, SOCK_STREAM,0);
    struct sockaddr_in local;
    memset(&local,0, sizeof(local));
    local.sin_port = htons(8888);
    local.sin_family= AF_INET;
    local.sin_addr.s_addr = inet_addr(
        "127.0.0.1"
    );

    bind(sock, (struct sockaddr*)&local, sizeof(local));

    listen(sock, 5);

    int epoll_fd = epoll_create(256);

    struct epoll_event reg_ev;
    struct epoll_event should_be_handled_evs[64];
    memset(&reg_ev, 0, sizeof(reg_ev));
    memset(should_be_handled_evs, 0, sizeof(should_be_handled_evs));

    reg_ev.events = EPOLLIN;
    reg_ev.data.fd = sock;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock, &reg_ev);
    while(true)
    {

        // strace ./a.out
        // check be blocked by select or epoll
        auto read_num = epoll_wait(epoll_fd, should_be_handled_evs, -1, 5000);
        for( int i = 0; i < read_num ; i++)
        {

        }
    }
}