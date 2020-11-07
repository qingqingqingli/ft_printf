[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/qingqingqingli/ft_printf)

## ft_printf
***The aim of this project is to recode the printf function from the C Library.***

In this project, you can learn how to use variadic arguments. More importantly, you can challenge yourself to structure the code well, so it can be extended to different usecases.

## Technical considerations

- Allowed functions: ```malloc```, ```free```, ```write```, ```va_start```, ```va_arg```, ```va_copy```, ```va_copy```
- All heap allocated memory space must be properly freed when necessary
- It will manage the following conversions: ```cspdiuxX%```
- It will manage any combination of ```-0.*``` flags and minimum field width with all conversions

## How to test
> Run the following commands
> You can replace the ```test.c``` with your own test file

```shell
$ git clone https://github.com/qingqingqingli/ft_printf
$ cd ft_printf
$ make
$ gcc test.c libftprintf.a
$ ./a.out
```
## Examples

- Create ```libftprint.a``` and compile with ```test.c```

![ft_printf_1](https://github.com/qingqingqingli/readme_images/blob/master/ft_printf_1.png)

- Run ```a.out``` to view the test results (*with some examples*).

![ft_printf_2](https://github.com/qingqingqingli/readme_images/blob/master/ft_printf_2.png)

![ft_printf_4](https://github.com/qingqingqingli/readme_images/blob/master/ft_printf_4.png)

![ft_printf_5](https://github.com/qingqingqingli/readme_images/blob/master/ft_printf_5.png)

![ft_printf_6](https://github.com/qingqingqingli/readme_images/blob/master/ft_printf_6.png)

![ft_printf_3](https://github.com/qingqingqingli/readme_images/blob/master/ft_printf_3.png)
