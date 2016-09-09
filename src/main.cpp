#include <boost/lexical_cast.hpp>
#include <sys/socket.h>
#include <map>
#include <cweb.h>

int main(void)
{
    Cweb cweb;
    std::map<std::string, std::string> core_site_conf = cweb.get_conf("core-site");
    int server_sock = -1;
    u_short port = 0;
    try {
        port = boost::lexical_cast<u_short>(core_site_conf["port"]);
    } catch (boost::bad_lexical_cast& e) {
        port = 0;
        std::cout << "list port: " << port << " isn't a ushort "
            "number, will set by a random port." << std::endl;
    }
    int client_sock = -1;
    struct sockaddr_in client_name;
    socklen_t client_name_len = sizeof(client_name);
    //pthread_t newthread;


    server_sock = cweb.startup(&port);
    printf("httpd running on port %d\n", port);

    while (1) {
        client_sock = accept(server_sock,
                (struct sockaddr *)&client_name,
                &client_name_len);
        if (client_sock == -1)
            cweb.error_die("accept");
        cweb.accept_request(client_sock);
    }

    close(server_sock);

    return(0);
}
