Vector2 = {};

local CreateVector = function(x, y)
    local self = {};

    self.x, self.y = x, y;

    self.ToArr = function()
        return {self.x, self.y};
    end

    return self;
end

Vector2.New = function(x, y)
    return CreateVector(x or 0.0, y or 0.0);
end

Vector2.Distance = function(value1, value2)
    local x = value1.x - value2.x;
    local y = value1.y - value2.y;

    return math.sqrt((x * x) + (y * y));
end

Vector2.ObjDistance = function(obj1, obj2)
    return Vector2.Distance(obj1.position, obj2.position);
end