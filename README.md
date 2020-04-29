# RPG: Documentation
# LUA API
## Vector2
Vector2 are essentially positions, they contain two coordinates x and y.
### How to create a Vector2
```lua
-- Vector2.New(x: float || 0.0 , y: float || 0.0 );
local x = 10;
local y = 20;
local Pos = Vector2.New(x, y);
```
Function Prototype | Returns | What it does
------------ | ------------- | -------------
```Pos.ToArr(void)``` | ```position: array``` | Returns the position as an array.

### Vector2 Interactions
Function Prototype | Returns | What it does
------------ | ------------- | -------------
```Vector2.Distance(v1: Vector2, v2: Vector2)``` | ```distance: float``` | Returns the distance between two vectors.
```Vector2.ObjDistance(obj1: Object, obj2: Object)``` | ```distance: float``` | Returns the distance between two objects.
## Objects
### How to create an object:
```lua
-- API.AddObject(path: string);
local Object = API.AddObject("image_path");
```
Function Prototype | Returns | What it does
------------ | ------------- | -------------
```Object.GetPosition(void)``` | ```position: Vector2``` | Returns the object's position.
```Object.SetPosition(x: integer, y: integer)``` | ```void``` | Sets the object's position.
```Object.GetScale(void)``` | ```scale: integer``` | Returns the object's scale.
```Object.GetSize(void)``` | ```width: integer, height: integer``` | Returns the object's size.
```Object.SetScale(scale: integer)``` | ```void``` | Sets the object's scale.
```Object.MouseHover(void)``` | ```hover: bool``` | Returns ``true`` if the mouse is hover the object, ``false`` otherwise.
```Object.ChangeTexture(path: string)``` | ```void``` | Sets the object texture to the specified path.
```Object.SetVisible(visible: bool)``` | ```void``` | Sets whether or not the object is visible.
```Object.SetRect(left: integer, top: integer, width: integer, height: integer)``` | ```void``` | Sets the object rectangle.
```Object.SetColor(color: Color)``` | ```void``` | Sets the object color.
```Object.Destroy(void)``` | ```void``` | Destroys the object.
## Texts
```lua
-- API.AddText(text: string, [font: string]);
local Txt = API.AddText("Text");
```
Function Prototype | Returns | What it does
------------ | ------------- | -------------
```Txt.SetString(str: string)``` | ```void``` | Sets the text's string.
```Txt.SetPosition(x: integer, y: integer)``` | ```void``` | Sets the text's position.
```Txt.SetSize(size: integer)``` | ```void``` | Sets the text's size.
```Txt.SetOutlineColor(color: Color, [thickness: integer])``` | ```void``` | Sets the text's outline color.
```Txt.SetColor(color: Color)``` | ```void``` | Sets the text's color.
```Txt.SetVisible(visible: bool)``` | ```void``` | Sets whether or not the text is visible.
```Txt.Destroy(void)``` | ```void``` | Destroys the text
## Shapes
```lua
-- API.AddShape(type: integer);
local Shape = API.AddShape(0);
```
Function Prototype | Returns | What it does
------------ | ------------- | -------------
```Shape.SetPosition(x: integer, y: integer)``` | ```void``` | Sets the shape's position.
```Shape.SetSize(width: integer, height: integer)``` | ```void``` | Sets the shape's size.
```Shape.SetFillColor(color: color)``` | ```void``` | Sets the shape's fill color.
```Shape.SetVisible(visible: bool)``` | ```void``` | Sets whether or not the shape is visible.
```Shape.Destroy(void)``` | ```void``` | Destroys the shape
## Misc
Others functions that aren't specifically object oriented.
Function Prototype | Returns | What it does
------------ | ------------- | -------------
```API.QuitGame(void)``` | ```void``` | Quits the game.
```API.SetCursor(cursor: integer)``` | ```void``` | Sets the cursor.
```API.GetCursorPos(void)``` | ```Vector2``` | Gets the cursor position.
```API.PlayMusic(path: string)``` | ```void``` | Plays the specified music on loop
```API.PlaySound(path: string)``` | ```void``` | Plays the specified sound once