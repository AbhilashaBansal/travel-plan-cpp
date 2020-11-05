const express = require('express');
const app = express();

//middlewares for data exchange in proper format, in post requests
app.use(express.urlencoded({extended: true}));
app.use(express.json());
app.set('view engine', 'hbs');

app.use("/", express.static(__dirname + '/public'));

app.use('/bookplan/', (req, res)=>{
    res.sendFile(__dirname + "/public/booking.html");
})

app.use('/bookpackage/', (req, res)=>{
    res.sendFile(__dirname + "/public/booking.html");
})

app.post('/finalplan/', (req, res)=>{
    // req.body.plan = true;
    console.log(req.body);
    res.render('book_rec', {details: req.body});
});

app.get('/hey', (req, res)=>{
    res.send("Hey, you are here!");
})

app.listen(4444, ()=>{
    console.log("Server started at http://localhost:4444");
})
