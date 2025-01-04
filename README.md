# RevShell
A basic reverse shell that connects to a server, sends an HTTP request, and retrieves a response.

## Features
- Connects to a server using TCP.
- Sends a simple HTTP GET request.
- Displays the response received from the server.

## Requirements
- Visual Studio 2019 or higher
- Windows SDK (for access to Windows APIs)
- NodeJS

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/nffdev/RevShell.git
   ```
2. Open the project in Visual Studio.
3. Compile the project using the `Release` or `Debug` configuration.
4. Go to the server's directory
5. Open a terminal
6. Type :
  ```bash
  node server.js
  ```

## Use 

1. Compile and run the application.
2. Run the server
3. Wait for a connection

## TECHNICAL DETAILS

- **Libraries**: `ws2_32.lib` for Winsock functions.
- **Protocol**: Uses IPv4 and TCP sockets.
- **Server Details**: Configured to connect to `127.0.0.1` (localhost) on port `8080`.
- **HTTP Request**: Sends a minimal `GET /` request.
- **Initialization**: Sets up Winsock with `WSAStartup`.
- **Socket Creation**: Creates a TCP socket using `WSASocket`.
- **Connection**: Connects to the specified IP and port using `WSAConnect`.
- **Data Transmission**: Sends an HTTP GET request with `send`.
- **Response Handling**: Reads the server's response using `recv` and displays it.
- **Cleanup**: Properly closes the socket and cleans up Winsock resources with `closesocket` and `WSACleanup`.

## Resources

- [Official Microsoft documentation on Windows APIs](https://docs.microsoft.com/en-us/windows/win32/)

## Notes

- Modify the `ip` and `port` variables in the code to connect to a different server or port.
- Ensure the server is configured to accept connections and respond to HTTP GET requests.

## Demo

![Demo](https://raw.githubusercontent.com/nffdev/RevShell/main/demo.gif)
