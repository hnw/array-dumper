# php-arraydumper

A PHP extension describing internal array property

## INSTALL

```
git clone https://github.com/hnw/php-arraydumper.git
cd php-arraydumper
phpize
./configure
make
make install
```

After install, add these lines to your php.ini

```ini
extension=arraydumper.so
```

## SYSTEM REQUIREMENTS

- PHP: 7.0.0+

## USAGE

```php
<?php
$a1 = [1 => "foo", 3 => "bar"];
var_dump(is_packed_array($a1)); // true

$a2 = [3 => "foo", 1 => "bar"];
var_dump(is_packed_array($a2)); // false
```

## LICENSE

The MIT License

Copyright (c) 2017 Yoshio HANAWA

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
