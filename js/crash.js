// Generated by CoffeeScript 1.7.1
(function() {
  var param1, recursive;

  param1 = 0;

  recursive = function() {
    param1 = param1 + 1;
    print(param1);
    if (param1 < 1000) {
      return recursive();
    }
  };

  recursive();

}).call(this);