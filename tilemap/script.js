const WIDTH = 320;
const HEIGHT = 240;
const TILESHEET_WIDTH = 140;
const TILESHEET_HEIGHT = 320;
const TILE_WIDTH = 20;
const TILE_HEIGHT = 20;
const ROWS = WIDTH / TILE_WIDTH;
const COLUMNS = HEIGHT / TILE_HEIGHT;
const TILESHEET_ROWS = TILESHEET_WIDTH / TILE_WIDTH;
const TILESHEET_COLUMNS = TILESHEET_HEIGHT / TILE_HEIGHT;

const container = document.getElementById("container")

const tilemap = new Image();
tilemap.src = "demo.png";
tilemap.crossOrigin = "Anonymous";

let children = [];
let tileData = [];
let tiles = [];

class Tile 
{
    constructor(data, id)
    {
        this.data = data;
        this.id = id;
    }
}

const temporary = document.createElement("canvas");
temporary.width = TILESHEET_WIDTH;
temporary.height = TILESHEET_HEIGHT;
temporary.classList.add("temporary")
document.body.append(temporary);
const context = temporary.getContext("2d");

for(let i = 0; i < ROWS * COLUMNS; i++)
{
    tiles.push({});
    
    const child = document.createElement("canvas");
    child.width = TILE_WIDTH;
    child.height = TILE_HEIGHT;
    child.id = "child";
    child.setAttribute("index", i);
    child.setAttribute("x", i % ROWS);
    child.setAttribute("y", Math.floor(i / ROWS));
    
    container.append(child);
    children.push(child);

    child.addEventListener("click", () => DrawTile(child, i));
}

const buttonList = document.getElementById("list");

tilemap.addEventListener("load", () => 
{
    context.drawImage(tilemap, 0, 0, TILESHEET_WIDTH, TILESHEET_HEIGHT);
    for(let i = 0; i < TILESHEET_ROWS * TILESHEET_COLUMNS; i++)
    {
        const data = context.getImageData((i % TILESHEET_ROWS) * TILE_WIDTH, Math.floor(i / TILESHEET_ROWS) * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
        tileData.push(new Tile(data, i));;

        const button = document.createElement("button");
        const imageCanvas = document.createElement("canvas");
        imageCanvas.width = TILE_WIDTH;
        imageCanvas.height = TILE_HEIGHT;
        button.append(imageCanvas);
        const imageCanvasContext = imageCanvas.getContext("2d");
        imageCanvasContext.putImageData(data, 0, 0);
        buttonList.append(button);

        button.addEventListener("click", () => 
        {
            selected = i;
        });
    }
});

let selected = 0;

function DrawTile(child, i)
{
    const ctx = child.getContext("2d");
    ctx.putImageData(tileData[selected].data, 0, 0);

    tiles[i] = 
    {
        id: tileData[selected].id,
        x: (i % ROWS) * TILE_WIDTH,
        y: (Math.floor(i / ROWS)) * TILE_HEIGHT
    };
}

const exportButton = document.getElementById("export");
exportButton.addEventListener("click", () => 
{
    let filtered = tiles.filter(e => Object.keys(e).length != 0);
    for(let i = 0; i < filtered.length; i++)
    {
        filtered[i] = `${ filtered[i].id }|${ filtered[i].x }|${ filtered[i].y }`;
    }
    console.log(filtered.toString().replace(/,/g, "\n"));
});