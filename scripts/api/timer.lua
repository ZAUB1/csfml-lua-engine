Threads = {};
RPG = {};
Listeners = {};
RPG.cTick = 1;

Listeners["ready"] = {};

_G.RPG = RPG;

RPG.OnTick = function(identifier, cb)
    table.insert(Threads, {
        identifier = identifier,
        coroutine = coroutine.create(cb),
        wakeTime = 0,
    });
end

RPG.Wait = function(time)
    local toWait = 0;
    coroutine.yield();
    repeat coroutine.yield(); toWait = toWait + 1 until toWait > time;
end

RPG.On = function(name, cb)
    if not (Listeners[name]) then
        Listeners[name] = {}
    end

    table.insert(Listeners[name], cb);
end

function stringsplit(inputstr, sep)
    if sep == nil then
        sep = "%s"
    end

    local t = {};
    local i = 1;

    for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
        t[i] = str
        i = i + 1
    end

    return t
end

function tick()
    --print("[DEBUG] Lua tick called: " .. RPG.cTick);
    RPG.cTick = RPG.cTick + 1;

    for i, thread in ipairs(Threads) do
        local status = coroutine.status(thread.coroutine);

        if (status == "dead") then
            table.remove(Threads, i);
        else
            local res, err = coroutine.resume(thread.coroutine);

            if (not res) then
                print("LUA ERROR ON TICK : " .. thread.identifier.. "\n -> " .. err);
                table.remove(Threads, i);
            end
        end
    end
end

function event(name, additional)
    -- print("[DEBUG] Lua event called: " .. name);

    if (name == "ready") then
        return;
    end

    if (Listeners[name]) then
        for k, v in pairs(Listeners[name]) do
            if (additional) then
                if (string.match(name, "sf")) then
                    local splitted = stringsplit(additional, ", ");
                    local data = {
                        mouse = {
                            x = tonumber(splitted[1]),
                            y = tonumber(splitted[2])
                        },
                        key = tonumber(splitted[3])
                    }
                    v(data);
                else
                    v(additional);
                end
            else
                v(nil);
            end
        end
    end
end

RPG.Emit = function(name, additional)
    return event(name, additional);
end

function ready()
    for _, v in pairs(Listeners["ready"]) do
        v();
    end
end