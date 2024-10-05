const logout = () => {
  localStorage.removeItem("token");
  window.location.href = "/";
}

const showFlag = async () => {
  const token = localStorage.getItem("token");
  const decoded = parseJwt(token);
  const role = decoded.role;

  if (role !== "admin") {
      alert("Oops, only users logged in as admin are allowed to see the flag");
      return;
  }

  try {
      const response = await fetch(FLAG_URL, {
          method: 'GET',
          headers: {
              'Authorization': `Bearer ${token}`
          }
      });

      if (response.ok) {
          const data = await response.json();
          alert(`SecuriNets{${data.flag}}`);
      } else {
          alert("Internal Server Error! Try again later.");
      }
  } catch (error) {
      alert("Internal Server Error! Try again later.");
  }
};

const parseJwt = (token) => {
  const base64Url = token.split(".")[1];
  const base64 = base64Url.replace(/-/g, "+").replace(/_/g, "/");
  const jsonPayload = decodeURIComponent(
    atob(base64)
      .split("")
      .map((c) => {
        return "%" + ("00" + c.charCodeAt(0).toString(16)).slice(-2);
      })
      .join("")
  );

  return JSON.parse(jsonPayload);
};

const isTokenValid = (token) => {
  if (!token) return false;

  try {
    const parts = token.split(".");
    if (parts.length !== 3) return false;

    const header = JSON.parse(atob(parts[0]));
    const payload = JSON.parse(atob(parts[1]));

    const currentTime = Math.floor(Date.now() / 1000);
    if (payload.exp && payload.exp < currentTime) {
      return false;
    }

    return true;
  } catch (e) {
    return false;
  }
};

const updateWelcomeMessage = () => {
  const decoded = parseJwt(currentToken);
  const role = decoded.role;

  const welcomeMessage = document.getElementById("welcomeMessage");
  const adminImage = document.getElementById("adminImage");

  if (role === "guest") {
    welcomeMessage.textContent = "Welcome, Guest!";
    adminImage.style.display = "none";
  } else if (role === "admin") {
    welcomeMessage.textContent = "Welcome, Admin!";
    adminImage.style.display = "block";
  } else {
    logout();
  }
};

let currentToken = localStorage.getItem("token");
if (!currentToken || !isTokenValid(currentToken)) {
  logout();
} else {
  updateWelcomeMessage();
}

setInterval(() => {
  const newToken = localStorage.getItem("token");

  if (newToken !== currentToken) {
    if (!isTokenValid(newToken)) {
      logout();
    } else {
      currentToken = newToken;
      updateWelcomeMessage();
    }
  }
}, 100);
