document
  .getElementById("loginForm")
  ?.addEventListener("submit", async (event) => {
    event.preventDefault();
    const username = document.getElementById("username").value;
    const password = document.getElementById("password").value;

    const response = await fetch("/login", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ username, password }),
    });

    const data = await response.json();

    if (response.ok) {
      localStorage.setItem("token", data.token);
      window.location.href = "/welcome";
    } else {
      alert(data.message);
    }
  });

if (window.location.pathname === "/welcome") {
  const token = localStorage.getItem("token");
  if (token) {
    const decoded = JSON.parse(atob(token.split(".")[1]));
    document.getElementById(
      "welcomeMessage"
    ).textContent = `Welcome, ${decoded.username}!`;
  } else {
    window.location.href = "/";
  }
}
