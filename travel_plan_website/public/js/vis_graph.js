onload = function(){

    const graph_container = document.getElementById('graph');

    const places = ["Delhi", "Mumbai", "Hong Kong", "Tokyo", "Bangkok", "Singapore", "Sydney (Australia)", "Melbourne (Australia)",
    "Dubai", "Cairo", "Moscow", "Stockholm", "Seoul", "Canada", "San Francisco (USA)",
    "Washington DC (USA)", "LA (USA)", "Chicago (USA)", "New York (USA)", "Cape Town (South Africa)", "Rio (Brazil)", "Santiago", "Mexico City",
    "Peru", "Miami (USA)", "London", "Berlin (Germany)", "Rome", "Paris", "Spain", "Havana"];

    const continents = ["Asia", "Asia", "Asia", "Asia", "Asia", "Asia", "Aus", "Aus", 
    "Asia", "Asia", "Asia", "Eur", "Asia", "USA", "USA", 
    "USA", "USA", "USA", "USA", "Africa", "SouthAm", "SouthAm", "USA", 
    "SouthAm", "USA", "Eur", "Eur", "Eur", "Eur", "Eur", "USA"];

    const flights = [ ["Delhi", "Dubai", 7500, 3.35],
        ["Delhi", "Mumbai", 1400, 2.05],
        ["Delhi", "Bangkok", 6300, 4.0],
        ["Delhi", "Moscow", 20000, 14.0],
        ["Delhi", "London", 25500, 9.25],
        ["Mumbai", "Hong Kong", 17000, 12.55],
        ["Mumbai", "Cape Town (South Africa)", 40000, 18.10],
        ["Mumbai", "London", 24500, 9.15],

        ["Dubai", "Cairo", 13000, 6.00],
        ["Dubai", "New York (USA)", 61000, 18.25],

        ["Cairo", "London", 13000, 5.20],
        ["Moscow", "Stockholm", 6900, 7.0],
        ["Stockholm", "London", 3500, 2.40],
        ["Stockholm", "Berlin (Germany)", 5300, 4.1],

        ["Hong Kong", "Tokyo", 9350, 3.55],
        ["Bangkok", "Singapore", 5500, 2.30],
        ["Singapore", "Melbourne (Australia)", 47000, 7.25],
        ["Singapore", "Sydney (Australia)", 19600, 7.45],

        ["Sydney (Australia)", "Melbourne (Australia)", 3500, 1.30],

        ["Tokyo", "Sydney (Australia)", 66000, 9.5],
        ["Tokyo", "Seoul", 9200, 2.40],
        ["Tokyo", "Canada", 32350, 12.50],
        ["Tokyo", "New York (USA)", 29300, 18.10],
        ["Tokyo", "LA (USA)", 25000, 18.30],
        ["Tokyo", "San Francisco (USA)", 25000, 18.30],

        ["Canada", "LA (USA)", 8500, 5.14],
        ["Canada", "San Francisco (USA)", 8000, 5.40],
        ["Canada", "Chicago (USA)", 7700, 1.50],
        ["Canada", "Washington DC (USA)", 9100, 1.27],

        ["London", "Rio (Brazil)", 19200, 15.47],
        ["London", "Washington DC (USA)", 21000, 11.00],
        ["London", "New York (USA)", 10000, 8.00],
        ["London", "Paris", 2800, 7.15],
        ["London", "Rome", 1750, 2.55],
        ["London", "Berlin (Germany)", 1400, 1.50],

        ["Rome", "Cape Town (South Africa)", 19800, 15.20],
        ["Rome", "Paris", 1000, 2.15],
        ["Rome", "Berlin (Germany)", 4400, 3.00],

        ["Paris", "Berlin (Germany)", 3500, 3.00],
        ["Paris", "Cape Town (South Africa)", 21300, 16.00],
        ["Paris", "New York (USA)", 13500, 11.00],
        ["Paris", "Washington DC (USA)", 15500, 16.00],

        ["Cape Town (South Africa)", "Rio (Brazil)", 52500, 41.00],
        ["Cape Town (South Africa)", "Washington DC (USA)", 27400, 24.00],
        ["Cape Town (South Africa)", "New York (USA)", 27800, 22.15],
        ["Cape Town (South Africa)", "Dubai", 22000, 24.00],

        ["Rio (Brazil)", "Santiago", 7500, 5.40],
        ["Rio (Brazil)", "Spain", 16500, 15.00],
        ["Santiago", "Peru", 4400, 3.49],
        ["Santiago", "Mexico City", 1700, 9.45], 

        ["Spain", "Peru", 19900, 12.00],
        ["Spain", "London", 3700, 2.25],
        ["Spain", "Berlin (Germany)", 1000, 4.00],
        ["Spain", "Paris", 2500, 2.00],
        ["Spain", "Rome", 1250, 2.55],
        ["Spain", "Dubai", 14450, 24.00], 
        ["Spain", "Delhi", 17800, 12.30],
        ["Spain", "New York (USA)", 10500, 10.00],

        ["Mexico City", "New York (USA)", 11000, 5.15],
        ["Mexico City", "LA (USA)", 7300, 4.20],
        ["Mexico City", "Washington DC (USA)", 19300, 4.10],
        ["Mexico City", "Chicago (USA)", 8700, 4.10],
        ["Mexico City", "Peru", 8250, 8.00],
        ["Mexico City", "Havana", 12750, 9.00],

        ["Peru", "Miami (USA)", 6500, 7.00],
        ["Peru", "Washington DC (USA)", 7500, 10.00],
        ["Peru", "Havana", 21000, 7.40],
        ["Peru", "LA (USA)", 20000, 9.00], 
        ["Peru", "San Francisco (USA)", 18000, 14.00],

        ["New York (USA)", "Delhi", 26000, 14.00],
        ["New York (USA)", "Chicago (USA)", 2500, 2.00], 
        ["New York (USA)", "Washington DC (USA)", 5500, 1.15],
        ["New York (USA)", "San Francisco (USA)", 6400, 6.30],
        ["New York (USA)", "LA (USA)", 4200, 7.00],
        ["New York (USA)", "Miami (USA)", 2500, 2.55],
        ["New York (USA)", "Canada", 5200, 1.40],

        ["Chicago (USA)", "Delhi", 26500, 16.00],
        ["Chicago (USA)", "LA (USA)", 2750, 4.30], 
        ["Chicago (USA)", "San Francisco (USA)", 4500, 4.50],
        ["Chicago (USA)", "Washington DC (USA)", 2250, 1.52], 

        ["LA (USA)", "Washington DC (USA)", 4000, 4.45],
        ["LA (USA)", "San Francisco (USA)", 2600, 1.20], 
        ["LA (USA)", "Miami (USA)", 3750, 4.40],
        ["LA (USA)", "Delhi", 24000, 24.00],
        ["LA (USA)", "Dubai", 31500, 15.55], 
        ["LA (USA)", "San Francisco (USA)", 7000, 8.00] 
    ]

    
    let vertices = [];
    let labels = {};
    for(let i=0; i<places.length; i++){
        if(places[i]=="Delhi"){
            vertices.push({id:i+1, label: places[i], x:0, y:0, group: continents[i]});
        }
        else if(places[i]=="New York (USA)"){
            vertices.push({id:i+1, label: places[i], x:-100, y:100, group: continents[i]});
        }
        else{
            vertices.push({id:i+1, label: places[i], group: continents[i]});
        }
        labels[places[i]] = i+1;
    }

    let edges = [];
    for(let i=0; i<86; i++){
        edges.push({from: labels[flights[i][0]], to: labels[flights[i][1]]});
    }
        
    const data = {
        nodes: new vis.DataSet(vertices),
        edges: new vis.DataSet(edges)
    };
    

    const options = {
        edges: {
            color: "black",
            physics: true,
            labelHighlightBold: true,
            font: {
                size: 20
            }
        },
        nodes: {
            borderWidth: 2,
            color: {
                border: "palevioletred",
                background: "steelblue",
                highlight: {
                    border: "palevioletred",
                    background: "powderblue"
                },

            },
            // font: '20px arial hotpink',
            heightConstraint: 30,
            scaling: {
                label: false
            },
            shape: 'image',
            image: "./images/plane3.png",
        },
        groups: {
            Aus: {font: '18px arial orchid'},
            USA: {font: '18px arial deeppink'},
            Africa: {font: '18px arial firebrick'},
            Asia: {font: '18px arial mediumvioletred'},
            Eur: {font: '18px arial hotpink'},
            SouthAm: {font: '18px arial purple'}
        }
    };

    const network = new vis.Network(graph_container, data, options);
    //network.setOptions(options);
    //network.setData(data);

};

