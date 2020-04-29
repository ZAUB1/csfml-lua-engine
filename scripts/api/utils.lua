function GetAllObjects(t)
    local objs = {}
    if type(t) ~= "table" then
        return false;
    end
    for k, v in pairs(t) do
        if type(v) == "table" and v.id then
            table.insert(objs, v);
        end
    end
    return objs;
end

function Rect(x, y, width, height)
    local rect = {};
    rect.x = x;
    rect.y = y;
    rect.width = width;
    rect.height = height;
    return rect;
end

function IsInRect(rect, x, y)
    if x >= rect.x and x <= rect.x + rect.width then
        if y >= rect.y and y <= rect.y + rect.height then
            return true;
        end
    end
    return false;
end

function Color(r, g, b, a)
    local color = {};
    if not a then a = 255 end
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
end