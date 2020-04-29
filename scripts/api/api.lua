API = {};
_G.API = API;
GAME = {}
GAME.OBJECTS = {}
GAME.CURSOR = {}

Engine.On("ready", function()
    if (GAME.Main) then
        GAME.Main();
    end
end);

local CreateObject = function(path) --Main object class
    local self = {};

    self.id, self.height, self.width = api_add_object(path);
    self.path = path;
    self.visible = 1;
    self.position = Vector2.New(0, 0);

    self.GetPosition = function()
        return api_get_obj_pos(self.id);
        --return self.position.x, self.position.y;
    end

    self.SetPosition = function(x, y)
        self.position = Vector2.New(x, y);
        api_set_obj_pos(self.id, x, y);
    end

    self.GetSize = function()
        return api_get_obj_size(self.id);
    end

    self.GetScale = function()
        return api_get_obj_scale(self.id);
    end

    self.SetScale = function(scale)
        api_set_obj_scale(self.id, scale);
    end

    self.MouseHover = function()
        return api_is_mouse_over_obj(self.id);
    end

    self.ChangeTexture = function(path)
        api_set_texture(self.id, path);
    end

    self.SetVisible = function(visible)
        self.visible = visible;
        api_set_inactive_obj(self.id, visible);
    end

    self.SetRect = function(left, top, width, height)
        api_set_rect_obj(self.id, left, top, width, height);
        self.rect = Rect(left, top, width, height);
    end

    self.SetColor = function(color)
        api_set_obj_color(self.id, color.r, color.g, color.b, color.a);
    end

    self.IsObject = function()
        return (true);
    end

    self.Destroy = function()
        api_destroy_obj(self.id);
        GAME.OBJECTS[self.id] = nil;
    end

    GAME.OBJECTS[self.id] = self

    return GAME.OBJECTS[self.id];
end

Engine.On("sfEvtMouseButtonPressed", function()
    local pos_x, pos_y = API.GetCursorPos();
    for _, v in pairs(GAME.OBJECTS) do
        local sprite_x, sprite_y = v.GetPosition();
        local sprite_w, sprite_h = v.GetSize();
        if v.visible == 1 then
            if pos_x >= sprite_x and pos_x <= sprite_x + sprite_w then
                if pos_y >= sprite_y and pos_y <= sprite_y + sprite_h then
                    if (v.OnClick) then
                        v.OnClick();
                        break;
                    end
                end
            end
        end
    end
end);

Engine.On("sfEvtMouseMoved", function(data)
    GAME.CURSOR.x = data.mouse.x
    GAME.CURSOR.y = data.mouse.y
end)

local CreateText = function(str, font)
    local self = {};
    if not font then font = "oswald.ttf" end
    self.id = api_add_text(str, font);

    self.SetString = function(str)
        api_set_text_string(self.id, str);
    end

    self.SetPosition = function(x, y)
        api_set_text_position(self.id, x, y);
    end

    self.SetSize = function(size)
        api_set_text_size(self.id, size);
    end

    self.SetOutlineColor = function(color, tickness)
        if not tickness then tickness = 3 end;
        api_set_text_outline_color(self.id, color.r, color.g, color.b, color.a, tickness);
    end

    self.SetColor = function(color)
        api_set_text_fill_color(self.id, color.r, color.g, color.b, color.a);
    end

    self.SetVisible = function(visible)
        api_set_inactive_text(self.id, visible);
    end

    self.Destroy = function()
        api_destroy_text(self.id);
    end

    return self;
end

local CreateShape = function(type)
    local self = {};
    self.id = api_add_shape(type or 0);

    self.SetPosition = function(x, y)
        api_set_shape_position(self.id, x, y);
    end

    self.SetSize = function(width, height)
        api_set_shape_size(self.id, width, height);
    end

    self.SetFillColor = function(color)
        api_set_shape_fill_color(self.id, color.r, color.g, color.b, color.a);
    end

    self.SetVisible = function(visible)
        api_set_inactive_shape(self.id, visible);
    end

    self.Destroy = function()
        api_destroy_shape(self.id);
    end

    return self;
end

API.AddObject = function(path)
    return CreateObject(path);
end

API.AddText = function(str, font)
    return CreateText(str, font);
end

API.AddShape = function(type)
    return CreateShape(type);
end

API.QuitGame = function()
    api_quit_game();
end

API.SetCursor = function(cursor)
    api_set_cursor(cursor);
end

API.GetCursorPos = function()
    return api_get_cursor_pos();
end

API.SetCursorVisible = function(visible)
    api_set_cursor_visible(visible);
end

API.PlayMusic = function(path)
    api_play_music(path);
end

API.PlaySound = function(path)
    api_play_sound(path);
end