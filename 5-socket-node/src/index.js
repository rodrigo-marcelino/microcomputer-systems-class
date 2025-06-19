const express = require('express');
const app = express();
const port = 3000;

app.get('/', (req, res) => {
  res.send('Olá do servidor!');
});

const server = app.listen(port, () => {
  console.log(`Servidor escutando em http://localhost:${port}`);
});

const info = server.address();
console.log(`Socket de escuta em IP: ${info.address}, Porta: ${info.port}`);
