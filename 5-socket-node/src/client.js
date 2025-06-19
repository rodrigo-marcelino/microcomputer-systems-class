const net = require('net');

const client = new net.Socket();

// Initiate a connection on a given socket.
client.connect(3000, '127.0.0.1', () => {
  console.log('✅ Conectado ao servidor!');
  console.log(`📤 Cliente IP: ${client.localAddress}, Porta: ${client.localPort}`);
  console.log(`📥 Servidor IP: ${client.remoteAddress}, Porta: ${client.remotePort}`);

  client.write('Olá, servidor!');
});

client.on('data', (data) => {
  console.log(`📨 Resposta do servidor: ${data.toString()}`);
  client.end(); // Fecha a conexão após receber a resposta
});

client.on('close', () => {
  console.log('🔒 Conexão encerrada.');
});
