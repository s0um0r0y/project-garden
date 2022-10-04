const firebaseApp = firebase.initializeApp({ 
    apiKey: "AIzaSyAmFJYOo9yK4LgTHgtJ2nG4vEdkXxF4Ppw",
    authDomain: "proj-garden.firebaseapp.com",
    databaseURL: "https://proj-garden-default-rtdb.firebaseio.com",
    projectId: "proj-garden",
    storageBucket: "proj-garden.appspot.com",
    messagingSenderId: "172644062414",
    appId: "1:172644062414:web:3cd8cf72bdac71a877ac9f",
    measurementId: "G-E28S2JDKD4"
});
const db = firebaseApp.firestore();
const auth = firebaseApp.auth();

const register = () => {
    const email = document.getElementById('email').value
    const password=document.getElementById('password').value
    auth.createUserWithEmailAndPassword(email,password)
    .then((res) => {
        console.log(res.user)
    })
    .catch((err) => {
        alert(err.message)
        console.log(err.code)
        console.log(err.message)
    })
}

const login = () => {
    const email = document.getElementById('email').value
    const password=document.getElementById('password').value
    auth.signInWithEmailAndPassword(email,password)
    .then((res) => {
        console.log(res.user)
    })
    .catch((err) => {
        alert(err.message)
        console.log(err.code)
        console.log(err.message)
    })
}

const saveData = () => {
    const email = document.getElementById('email').value
    const password=document.getElementById('password').value

    db.collection('users')
    .add({
        email: email,
        password: password
    })
    .then((docRef) => {
        console.log("Document written with ID:",docRef.id);
    })
    .catch((error) => {
        console.error("error adding document:",error);
    });
}

const readData = () => {
    db.collection('users')
    .get()
    .then((data) =>{
        console.log(data.docs.map((item) =>{
            return {...item.data(),id:item.id}
        }))
    })
}

const txtToJson = require("txt-file-to-json");
const dataInJSON = txtToJson({ filePath: "/home/soumoroy/pythonstuff/proj_garden/proj_garden_data.txt" });
