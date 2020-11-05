
const places = ["Delhi", "Mumbai", "Hong Kong", "Tokyo", "Bangkok", "Singapore", "Sydney (Australia)", "Melbourne (Australia)",
    "Dubai", "Cairo", "Moscow", "Stockholm", "Seoul", "Canada", "San Francisco (USA)",
    "Washington DC (USA)", "LA (USA)", "Chicago (USA)", "New York (USA)", "Cape Town (South Africa)", "Rio (Brazil)", "Santiago", "Mexico City",
    "Peru", "Miami (USA)", "London", "Berlin (Germany)", "Rome", "Paris", "Spain", "Havana"
];

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

//adjacency list
m = {};
for(let i=0; i<places.length; i++){
    m[places[i]] = [];
}

for(let i=0; i<flights.length; i++){
    m[flights[i][0]].push([flights[i][1], flights[i][2]]);
    m[flights[i][1]].push([flights[i][0], flights[i][2]]);
}

parents = {};
//DIJKSTRA'S ALGORITHM 
function dijkstras (src){
    distances = {};
    places.forEach(city => {
        distances[city] = 1000000000;
    });

    distances[src] = 0;
    parents[src] = src;
    let pq = [];
    pq.push([src, 0]);

    while(pq.length!=0){
        //finding minimum distance place from pq
        let min_index = 0;
        for(let i=0; i<pq.length; i++){
            if(pq[i][1]<pq[min_index][1]){
                min_index=i;
            }
        }
        let pl = pq[min_index][0];
        let pl_d = pq[min_index][1];
        var rem = pq.splice(min_index, 1);

        m[pl].forEach(nbr_pair => {
            let nbr_name = nbr_pair[0];
            let nbr_dist = nbr_pair[1];
            if(pl_d + nbr_dist < distances[nbr_name]){
                let ind = pq.indexOf([nbr_name, distances[nbr_name]]);
                if(ind!=-1){
                    let rem = pq.splice(ind, 1);
                }
                parents[nbr_name] = pl;
                distances[nbr_name] = nbr_dist + pl_d;
                pq.push([nbr_name, distances[nbr_name]]);
            }
        });
    }    
    return distances;   
}

let dists = dijkstras("Delhi");
//console.log(dists);

onload = function(){
    let cards = document.getElementsByClassName("card-body");
    for(let i=0; i<cards.length; i++){
        let id = cards[i].id;
        let btn = cards[i].children[2];
        let span = cards[i].children[1].children[0];
        span.innerHTML = (distances[id]*2)+20000 + " INR, per person";
    }

    let navbar = document.getElementById("navbar");
    let sticky = navbar.offsetTop;

    window.onscroll = function(){
        sticky_nav();
    }
    
    function sticky_nav() {
        if (window.pageYOffset > sticky) {
            navbar.classList.add("sticky");
        } 
        else {
            navbar.classList.remove("sticky");
        }
    }
}
