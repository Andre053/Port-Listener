# Port Listener

- Utilizes C++ web sockets to listen on a particular port
- IP to listen on must be an environment variable (namely IP) or is set to localhost
- Takes command line arguments: first must be port number, second must be the maximum backlog count
- ss is compiled with clang 13.1.6 on arm64-apple-darwin21.4.0