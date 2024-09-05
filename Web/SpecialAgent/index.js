const express = require("express");

const app = express();

const PORT = process.env.PORT || 5001;

console.log(__dirname);

app.get("/", (req, res) => {
  if (req.headers["user-agent"] === "SpecialAgent") {
    res.sendFile(__dirname + "/flag.html");
  } else res.sendFile(__dirname + "/index.html");
});

app.listen(PORT, () => {
  console.log(`port open on ${PORT}`);
});
