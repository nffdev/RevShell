const http = require('http');

const ip = '127.0.0.1';
const port = 8080;

const server = http.createServer((req, res) => {
  console.log('New victim');

  if (req.method === 'GET') {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Hello, World!');
  } else {
    res.statusCode = 405;
    res.setHeader('Content-Type', 'text/plain');
    res.end('Method Not Allowed');
  }
});

server.listen(port, ip, () => {
  console.log(`Listening to : http://${ip}:${port}/`);
});
