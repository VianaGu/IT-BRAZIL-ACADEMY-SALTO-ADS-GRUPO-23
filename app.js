var firebase = require("firebase")
const { Board, Led } = require("johnny-five");
const board = new Board();

// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyBUiSKIMyoLcJaUeWD2jOYyXYFgToFD9MM",
  authDomain: "projetopagotto.firebaseapp.com",
  projectId: "projetopagotto",
  storageBucket: "projetopagotto.appspot.com",
  messagingSenderId: "73223446228",
  appId: "1:73223446228:web:216b1fe8527868a449e541",
  measurementId: "G-T9SGCEJ6LM"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);

board.on("ready", () => {
  const led = new Led(13);

  // This will grant access to the led instance
  // from within the REPL that's created when
  // running this program.
  board.repl.inject({
    led : led
  });


 
var starCountRef = firebase.database().ref('frente').on('value', (snapshot) => {
  let frente = snapshot.val();
  
});

});