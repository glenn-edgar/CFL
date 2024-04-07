-- Define a table to represent the stack
local Stack = {}

-- Metatable for the Stack
local stackMeta = {
    -- Push function to add an element to the stack
    push = function(self, value)
        table.insert(self, value)
    end,

    -- Pop function to remove and return the top element from the stack
    pop = function(self)
        return table.remove(self)
    end,
    -- Peek function to return the top element from the stack without removing it
    peek = function(self)
         return self[#self]
    end,
    -- Function to get the size of the stack
    size = function(self)
        return #self
    end,

    -- Function to check if the stack is empty
    isEmpty = function(self)
        return #self == 0
    end,

    -- Function to clear the stack
    clear = function(self)
        for i = #self, 1, -1 do
            table.remove(self)
        end
    end
}

-- Function to create a new stack
function create_stack()
    local newStack = {}
    setmetatable(newStack, {__index = stackMeta})
    return newStack
end
