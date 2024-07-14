<h1 align="center">
  TCP Server/Client using Socket Programming
</h1>

<h4 align="center">TCP server socket program (server - client) using C++.</h4>

## Table of Contents:
- [Introduction](#introduction)
- [Server Implementation](#server-implementation)
- [Client Implementation](#client-implementation)

## Introduction:
The TCP socket program implemented in C++ consists of both a server and a client designed to communicate over the local network using the loopback IP address, 127.0.0.1. This implementation exemplifies the fundamental principles of network programming, focusing on establishing reliable, bidirectional communication channels.
## Server Implementation:
The server component of the TCP socket program is responsible for setting up a listening socket on a predefined port. The server's primary functions include:
1. **Socket Creation:**
   - Utilizing the socket() function to create a new socket capable of handling TCP connections.

3. **Binding:**
   - Binding the socket to the loopback IP address (127.0.0.1) and the specified port, ensuring that the server listens for incoming connections on the local machine.

5. **Listening:**
   - Transitioning the socket to a listening state with the listen() function, allowing it to accept incoming connection requests.

7. **Accepting Connections:**
   - Using the accept() function to establish a connection with a client. This function blocks until a connection request is received, at which point it creates a new socket dedicated to the communication with the client.
9. **Data Exchange:**
    - Facilitating data exchange between the server and the connected client through the newly established socket using send() and recv() functions.
11. **Graceful Termination:**
    - Ensuring proper closure of the connection and the listening socket with the close() function to release all resources.

## Client Implementation:

The client component is designed to initiate a connection to the server and engage in data exchange. Key functionalities include:

1. **Socket Creation:**
   -  Similar to the server, the client creates a new socket using the socket() function, suitable for TCP communication.
2. **Connection to Server:**
   -  Using the connect() function, the client establishes a connection to the server's socket located at 127.0.0.1 and the predefined port. This initiates the communication session.
3. **Data Exchange:**
   -  Once connected, the client can send and receive data using the send() and recv() functions, engaging in meaningful communication with the server.
4. **Graceful Termination:**
   -  Properly closing the socket connection with the close() function to ensure resource cleanup and termination of the client session.
