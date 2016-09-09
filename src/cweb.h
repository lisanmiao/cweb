/* J. David's webserver */
/* This is a simple webserver.
 * Created November 1999 by J. David Blackstone.
 * CSE 4344 (Network concepts), Prof. Zeigler
 * University of Texas at Arlington
 */
/* This program compiles for Sparc Solaris 2.6.
 * To compile for Linux:
 *  1) Comment out the #include <pthread.h> line.
 *  2) Comment out the line that defines the variable newthread.
 *  3) Comment out the two lines that run pthread_create().
 *  4) Uncomment the line that runs accept_request().
 *  5) Remove -lsocket from the Makefile.
 */
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>
//#include <strings.h>
#include <string.h>
#include <sys/stat.h>
//#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
// added by lisanmiao at 2016/08/26
#include <iostream>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

class Cweb {
    private:
        std::map<std::string, std::string> core_site_conf;

        void bad_request(int);
        void cat(int, FILE *);
        void cannot_execute(int);
        void execute_cgi(int, const char *, const char *, const char *);
        int get_line(int, char *, int);
        void headers(int, const char *);
        void not_found(int);
        void serve_file(int, const char *);
        void unimplemented(int);
    public: 
        Cweb() {
            init_conf();
            read_conf();
            for (auto& it : core_site_conf) {
                std::cout << "core-site.xml name: " << it.first << std::endl;
                std::cout << "core-site.xml value: " << it.second << std::endl;
            }
        }
        void accept_request(int);
        void error_die(const char *);
        int startup(u_short *);
        void init_conf();
        void read_conf();
        std::map<std::string, std::string> get_conf(std::string conf_name);
};
