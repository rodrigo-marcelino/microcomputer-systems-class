// The node:net module provides an asynchronous network API for creating stream-based TCP or IPC servers (createServer) and clients (createConnection).

const net = require('net');

// Creates a new TCP or IPC server.
const server = net.createServer((socket) => {
  console.log('🟢 Novo cliente conectado!');
  console.log(`📥 Cliente IP: ${socket.remoteAddress}, Porta: ${socket.remotePort}`);
  console.log(`📤 Servidor IP: ${socket.localAddress}, Porta: ${socket.localPort}`);

  // Sends data on the socket.
  socket.write('Olá do servidor!');

  socket.on('data', (data) => {
    console.log(`📨 Mensagem do cliente: ${data.toString()}`);
  });

  socket.on('end', () => {
    console.log('🔚 Cliente desconectado.');
  });
});

// Sends data on the socket.
server.listen(4000, () => {
  console.log('🚀 Servidor escutando na porta 4000');
});
