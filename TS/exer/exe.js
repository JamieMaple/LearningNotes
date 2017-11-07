var myName = 'kevin';
var age = 40;
var vanVote = true;
var anything = 2;
var test = 'sdsfsdf';
var Color;
(function (Color) {
    Color[Color["red"] = 0] = "red";
    Color[Color["green"] = 1] = "green";
    Color[Color["yellow"] = 2] = "yellow";
})(Color || (Color = {}));
Color[0];
Color['red'];
anything = 'dog';
test = null;
