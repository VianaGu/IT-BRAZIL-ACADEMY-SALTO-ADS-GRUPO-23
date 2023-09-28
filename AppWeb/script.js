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


let frente = document.querySelector('btnfrente');
frente.addEventListener('click',() => {
  let estado = frente.getAttribute('data-state');

  if(estado == "off"){
    firebase.database().ref('frente').set('on');
  }
  else{
    firebase.database().ref('frente').set('off');
  }
});

firebase.database().ref('frente').on('value',snapshot => {
  let l = snapshot.val();
});