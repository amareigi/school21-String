#include "s21_string.h"
//рекурсивная функция записи числа в строку
void decimal_record_digit_to_str_func(long int digit, char *str,
                                      int len_of_dig) {
  long int tmp_num = digit % 10;
  digit = digit / 10;
  if (digit > 0) decimal_record_digit_to_str_func(digit, str, len_of_dig - 1);
  char ch_digit = tmp_num + '0';
  str[len_of_dig] = ch_digit;
}
//рекурсивная функция подсчёта длины числа
void decimal_digit_len_func(long int digit, int *len_of_dig) {
  *len_of_dig = *len_of_dig + 1;
  digit = digit / 10;
  if (digit > 0) decimal_digit_len_func(digit, len_of_dig);
}
// определяет необходимость оставить место под знак
void decimal_set_place_for_sing_func(long int *digit, config *flags) {
  if (*digit < 0) {
    *digit = -*digit;
    flags->is_negative = true;
  }
  if (flags->space || flags->plus || flags->is_negative)
    flags->place_for_sign = 1;
}
//получает число из аргументов для десятичного числа
void decimal_set_digit_func(long int *digit, va_list *vl, config *flags) {
  switch (flags->length) {
    case 'l':
      *digit = (long int)va_arg(*vl, long int);
      break;
    case 'h':
      *digit = (short)va_arg(*vl, int);
      break;
    default:
      *digit = (int)va_arg(*vl, int);
  }
}
//установка ширины, а так же точности для конкретного числа
void decimal_len_for_flags_func(config *flags, int len_of_dig,
                                int *len_for_flags) {
  *len_for_flags = len_of_dig;
  if (flags->width > *len_for_flags && flags->width > flags->accuracy) {
    *len_for_flags = flags->width;
    //тут больше или равно может быть нужно будет поправить
  } else if (flags->accuracy >= *len_for_flags) {
    *len_for_flags = flags->accuracy;
    if (flags->place_for_sign) *len_for_flags = *len_for_flags + 1;
  } else if (flags->place_for_sign) {
    *len_for_flags = *len_for_flags + 1;
  }

  *len_for_flags = *len_for_flags - len_of_dig - flags->place_for_sign;

  if (flags->accuracy - len_of_dig > 0) {
    flags->accuracy = flags->accuracy - len_of_dig;
    flags->zero = true;
    flags->set_accuracy = true;
  }
}
//запись знаков перед числом
void decimal_record_flags_before_dig_func(config *flags, int *len_for_flags,
                                          char *str, int *j) {
  //если нет флага минус, то нужно вначале поставить пробелы
  //если ширина больше accurancy и при этом число меньше accurancy написать
  //сначала пробелы, а потом нули когда зашли в точность
  while (!flags->minus &&
         ((!flags->zero && *len_for_flags > 0) ||
          (flags->set_accuracy && *len_for_flags > flags->accuracy))) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
  //запись знака
  if (flags->place_for_sign) {
    if (flags->space && !flags->is_negative) str[*j] = ' ';
    if (flags->is_negative) str[*j] = '-';
    if (!flags->is_negative && flags->plus) str[*j] = '+';
    (*j)++;
  }
  //запись нулей, если ширина числа, меньше точности
  while (flags->zero && *len_for_flags > 0 &&
         (flags->accuracy || !flags->set_accuracy)) {
    str[*j] = '0';
    (*j)++;
    (*len_for_flags)--;
    flags->accuracy--;
  }
}

//если флаг минус, прижать число к левому краю
void decimal_record_flags_after_dig_func(config *flags, int *len_for_flags,
                                         char *str, int *j) {
  while (flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}

void main_decimal_record_to_str_func(char *str, va_list *vl, int *j,
                                     config *flags) {
  long int digit = 0;
  int len_of_dig = 0;
  int len_for_flags = 0;
  decimal_set_digit_func(&digit, vl, flags);
  decimal_set_place_for_sing_func(&digit, flags);
  decimal_digit_len_func(digit, &len_of_dig);
  decimal_len_for_flags_func(flags, len_of_dig, &len_for_flags);
  decimal_record_flags_before_dig_func(flags, &len_for_flags, str, j);
  *j = *j + len_of_dig;  // для рекурсивной функции нужно зайти в конец индекса
                         // для числа
  decimal_record_digit_to_str_func(
      digit, str,
      *j - 1);  //-1 так как длина числа начинается с 1, а индексы с 0
  decimal_record_flags_after_dig_func(flags, &len_for_flags, str, j);
}
void unsigned_set_digit_func(unsigned long int *digit, va_list *vl,
                             config *flags) {
  switch (flags->length) {
    case 'l':
      *digit = (unsigned long int)va_arg(*vl, unsigned long int);
      break;
    case 'h':
      *digit = (unsigned short)va_arg(*vl, unsigned int);
      break;
    default:
      *digit = (unsigned int)va_arg(*vl, unsigned int);
  }
}
// определяет необходимость оставить место под знак
void unsigned_set_place_for_sing_func(config *flags) {
  if (flags->hash) {
    if (flags->number_base == 8) flags->place_for_sign = 1;
    if (flags->number_base == 16) flags->place_for_sign = 2;
  }
}
void unsigned_digit_len_func(unsigned long int digit, int *len_of_dig,
                             int number_base) {
  *len_of_dig = *len_of_dig + 1;
  digit = digit / number_base;
  while (digit > 0) {
    *len_of_dig = *len_of_dig + 1;
    digit = digit / number_base;
  }
}
void unsigned_len_for_flags_func(config *flags, int len_of_dig,
                                 int *len_for_flags) {
  *len_for_flags = len_of_dig;
  if (flags->width > *len_for_flags && flags->width > flags->accuracy) {
    *len_for_flags = flags->width;
  } else if (flags->accuracy >= *len_for_flags) {
    *len_for_flags = flags->accuracy;
    if (flags->place_for_sign == 1) *len_for_flags = *len_for_flags + 1;
    if (flags->place_for_sign == 2) *len_for_flags = *len_for_flags + 2;
  } else if (flags->place_for_sign == 1) {
    *len_for_flags = *len_for_flags + 1;
  } else if (flags->place_for_sign == 2) {
    *len_for_flags = *len_for_flags + 2;
  }

  *len_for_flags = *len_for_flags - len_of_dig - flags->place_for_sign;

  if (flags->accuracy - len_of_dig > 0) {
    flags->accuracy = flags->accuracy - len_of_dig;
    flags->zero = true;
    flags->set_accuracy = true;
  }
}
void unsigned_record_flags_before_dig_func(config *flags, int *len_for_flags,
                                           char *str, int *j) {
  while (!flags->minus &&
         ((!flags->zero && *len_for_flags > 0) ||
          (flags->set_accuracy && *len_for_flags > flags->accuracy))) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
  //запись знака
  if (flags->place_for_sign == 1) {
    str[*j] = '0';
    (*j)++;
  }
  if (flags->place_for_sign == 2) {
    str[*j] = '0';
    (*j)++;
    if (!flags->up_case) {
      str[*j] = 'x';
      (*j)++;
    }
    if (flags->up_case) {
      str[*j] = 'X';
      (*j)++;
    }
  }
  //запись нулей, если ширина числа, меньше точности
  while (flags->zero && *len_for_flags > 0 &&
         (flags->accuracy || !flags->set_accuracy)) {
    str[*j] = '0';
    (*j)++;
    (*len_for_flags)--;
    flags->accuracy--;
  }
}
char unsigned_digit_to_chr_func(unsigned long int tmp_dig, config *flags) {
  char symbol = '0';
  switch (tmp_dig) {
    case 10:
      symbol = (char)('a' - flags->up_case * 32);
      break;
    case 11:
      symbol = (char)('b' - flags->up_case * 32);
      break;
    case 12:
      symbol = (char)('c' - flags->up_case * 32);
      break;
    case 13:
      symbol = (char)('d' - flags->up_case * 32);
      break;
    case 14:
      symbol = (char)('e' - flags->up_case * 32);
      break;
    case 15:
      symbol = (char)('f' - flags->up_case * 32);
      break;
    default:
      symbol = (char)(tmp_dig + 48);
  }
  return symbol;
}
void unsigned_record_digit_to_str_func(unsigned long int digit, char *str,
                                       int len_of_dig, config *flags) {
  unsigned long int tmp_dig = digit % flags->number_base;
  digit = digit / flags->number_base;
  if (digit > 0)
    unsigned_record_digit_to_str_func(digit, str, len_of_dig - 1, flags);
  str[len_of_dig] = unsigned_digit_to_chr_func(tmp_dig, flags);
}
void unsigned_record_flags_after_dig_func(config *flags, int *len_for_flags,
                                          char *str, int *j) {
  while (flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}
void main_unsigned_record_to_str_func(char *str, va_list *vl, int *j,
                                      config *flags) {
  unsigned long int digit = 0;
  int len_of_dig = 0;
  int len_for_flags = 0;
  unsigned_set_digit_func(&digit, vl, flags);
  unsigned_set_place_for_sing_func(flags);
  unsigned_digit_len_func(digit, &len_of_dig, flags->number_base);
  unsigned_len_for_flags_func(flags, len_of_dig, &len_for_flags);
  unsigned_record_flags_before_dig_func(flags, &len_for_flags, str, j);
  *j = *j + len_of_dig;
  unsigned_record_digit_to_str_func(
      digit, str, *j - 1,
      flags);  //-1 так как длина числа начинается с 1, а индексы с 0
  unsigned_record_flags_after_dig_func(flags, &len_for_flags, str, j);
}
void double_set_func(long double *digit, va_list *vl, config *flags) {
  switch (flags->length) {
    case 'L':
      *digit = (long double)va_arg(*vl, long double);
      break;
    default:
      *digit = (double)va_arg(*vl, double);
  }
}

void double_check_accuracy_inf_nan_func(long double digit, config *flags) {
  if (!flags->dot) flags->accuracy = 6;
  if (flags->accuracy > 19) flags->accuracy = 19;
  if (digit != digit) {
    flags->is_nan = true;
    flags->error_digit = true;
    flags->accuracy = 0;
  }
  if (digit == S21_INF || digit == S21_NINF) {
    flags->is_inf = true;
    flags->error_digit = true;
    flags->accuracy = 0;
  }
  if (flags->error_digit) flags->hash = false;
}
void double_set_place_for_sign_func(long double *digit, config *flags) {
  if (*digit < 0) {
    *digit = -*digit;
    flags->is_negative = true;
  }
  if (flags->space || flags->plus || flags->is_negative)
    flags->place_for_sign = 1;
}
//находим целую часть числа
void double_get_int_part_func(long double digit,
                              unsigned long int *integ_part_of_digit,
                              int tmp_accuracy) {
  *integ_part_of_digit = (unsigned long int)digit;
  long double tmp_fract_part = 0.0;
  tmp_fract_part = digit - (*integ_part_of_digit);
  if (tmp_accuracy == 0) {  //если точность 0, округлить целую часть
    unsigned long int last_in_accuracy = 0;  //берём число после точки
    last_in_accuracy = (unsigned long int)(tmp_fract_part * 10);
    if (last_in_accuracy >= 5)  //если число после точки 5 или больше, то
                                //добавляем к последней цифре в точности единицу
      *integ_part_of_digit = *integ_part_of_digit + 1;
  }
}
//находим дробную часть числа
void double_get_fract_part_func(long double digit,
                                const unsigned long int *integ_part_of_digit,
                                unsigned long int *fract_part_of_digit,
                                int tmp_accuracy) {
  long double tmp_fract_part = 0.0;
  tmp_fract_part = digit - (*integ_part_of_digit);
  if (tmp_accuracy > 0)
    *fract_part_of_digit = 1;  // единичка тут вместо точки выступает, чтобы
                               // после точки нули не терялись
  while (tmp_accuracy > 0) {
    if (tmp_accuracy == 1) {  //для округления последней цифры в точности
      unsigned long int last_in_accuracy =
          0;  //берём последнее число для точности и одно сразу за ним
      last_in_accuracy = (unsigned long int)(tmp_fract_part * 10);
      tmp_fract_part =
          (tmp_fract_part * 10) - (unsigned long int)(tmp_fract_part * 10);
      unsigned long int after_last_in_accuracy =
          0;  //берём число после точности
      after_last_in_accuracy = (unsigned long int)(tmp_fract_part * 10);
      if (after_last_in_accuracy >=
          5)  //если число после точности 5 или больше, то добавляем к последней
              //цифре в точности единицу
        *fract_part_of_digit =
            (*fract_part_of_digit * 10) + last_in_accuracy + 1;
      else
        *fract_part_of_digit = (*fract_part_of_digit * 10) + last_in_accuracy;
      break;
    }
    *fract_part_of_digit =
        (*fract_part_of_digit * 10) + (unsigned long int)(tmp_fract_part * 10);
    tmp_accuracy--;
    tmp_fract_part =
        (tmp_fract_part * 10) - (unsigned long int)(tmp_fract_part * 10);
  }
}

//считаем длину частей включая точку
void double_len_func(unsigned long int integ_part_of_digit,
                     unsigned long int fract_part_of_digit,
                     int *len_of_integ_part, int *len_of_fract_part) {
  *len_of_integ_part = *len_of_integ_part + 1;
  integ_part_of_digit = integ_part_of_digit / 10;
  while (integ_part_of_digit > 0) {
    *len_of_integ_part = *len_of_integ_part + 1;
    integ_part_of_digit = integ_part_of_digit / 10;
  }
  if (fract_part_of_digit != 0) {
    *len_of_fract_part = *len_of_fract_part + 1;
    fract_part_of_digit = fract_part_of_digit / 10;
    while (fract_part_of_digit > 0) {
      *len_of_fract_part = *len_of_fract_part + 1;
      fract_part_of_digit = fract_part_of_digit / 10;
    }
  }
  //тут длина дробной части + 1 будет, т.к. в начале стоит 1,эта длина для точки
  //используется
}

void double_len_for_flags_func(config *flags, int len_of_dig,
                               int *len_for_flags) {
  *len_for_flags = len_of_dig;
  if (flags->width > *len_for_flags) {
    *len_for_flags = flags->width;
  } else if (flags->place_for_sign) {
    *len_for_flags = *len_for_flags + 1;
  }
  *len_for_flags = *len_for_flags - len_of_dig - flags->place_for_sign;
}

void double_record_flags_before_func(config *flags, int *len_for_flags,
                                     char *str, int *j) {
  //если нет флага минус и длна числа меньше ширины, то нужно вначале поставить
  //пробелы
  while (!flags->minus &&
         ((!flags->dzero || flags->error_digit) && *len_for_flags > 0)) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
  //запись знака
  if (flags->place_for_sign) {
    if (flags->space && !flags->is_negative) str[*j] = ' ';
    if (flags->is_negative) str[*j] = '-';
    if (!flags->is_negative && flags->plus) str[*j] = '+';
    (*j)++;
  }
  //запись нулей, если число меньше ширины и стоит флаг 0
  while (flags->dzero && *len_for_flags > 0) {
    str[*j] = '0';
    (*j)++;
    (*len_for_flags)--;
  }
}

void double_record_to_str_func(unsigned long int digit, char *str, int ptr,
                               int len_of_dig) {
  unsigned long int tmp_num = digit % 10;
  digit = digit / 10;
  len_of_dig--;
  if (len_of_dig > 0)
    double_record_to_str_func(digit, str, ptr - 1, len_of_dig);
  char ch_digit = tmp_num + '0';
  str[ptr] = ch_digit;
}

void double_record_nan_inf_to_str(char *str, int *j, config *flags) {
  if (flags->is_inf) {
    str[*j] = 'i';
    (*j)++;
    str[*j] = 'n';
    (*j)++;
    str[*j] = 'f';
    (*j)++;
  }
  if (flags->is_nan) {
    str[*j] = 'n';
    (*j)++;
    str[*j] = 'a';
    (*j)++;
    str[*j] = 'n';
    (*j)++;
  }
  //негативной inf нет так как минус поставится сам, так как установлен флаг
  // is_negative
}
void double_record_dot_to_str(char *str, int *j, config *flags,
                              int len_of_fract_part) {
  if (len_of_fract_part != 0 || flags->hash) {
    str[*j] = '.';
    (*j)++;
  }
}

void double_record_flags_after_func(config *flags, int *len_for_flags,
                                    char *str, int *j) {
  while (flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}
void main_double_record_to_str_func(char *str, va_list *vl, int *j,
                                    config *flags) {
  long double digit = 0;
  int len_of_integ_part = 0;
  int len_of_fract_part = 0;
  int len_for_flags = 0;
  unsigned long int integ_part_of_digit = 0;
  unsigned long int fract_part_of_digit = 0;
  double_set_func(&digit, vl, flags);
  double_check_accuracy_inf_nan_func(digit, flags);
  double_set_place_for_sign_func(&digit, flags);
  if (!flags->error_digit) {
    double_get_int_part_func(digit, &integ_part_of_digit, flags->accuracy);
    double_get_fract_part_func(digit, &integ_part_of_digit,
                               &fract_part_of_digit, flags->accuracy);
    double_len_func(integ_part_of_digit, fract_part_of_digit,
                    &len_of_integ_part, &len_of_fract_part);
  } else {
    len_of_integ_part = 3;
  }
  double_len_for_flags_func(flags, len_of_integ_part + len_of_fract_part,
                            &len_for_flags);
  double_record_flags_before_func(flags, &len_for_flags, str, j);
  if (!flags->error_digit) {
    *j = *j + len_of_integ_part;
    double_record_to_str_func(
        integ_part_of_digit, str, *j - 1,
        len_of_integ_part);  //-1 так как длина числа начинается с 1, а индексы
                             //с 0
  } else {
    double_record_nan_inf_to_str(str, j, flags);
  }
  double_record_dot_to_str(str, j, flags, len_of_fract_part);
  if (len_of_fract_part != 0) {
    *j = *j + len_of_fract_part -
         1;  // вот тут длинну уменьшили на один,  так как ведущая единица и
             // точку уже поставили
    double_record_to_str_func(
        fract_part_of_digit, str, *j - 1,
        len_of_fract_part -
            1);  //-1 так как длина числа начинается с 1, а индексы с 0
  }
  double_record_flags_after_func(flags, &len_for_flags, str, j);
}

void char_len_for_flags_func(config *flags, int *len_for_flags) {
  if (flags->width > 1) *len_for_flags = flags->width;
  *len_for_flags = *len_for_flags - 1;
}
//запись пробелов перед char
void char_record_flags_before_func(config *flags, int *len_for_flags, char *str,
                                   int *j) {
  //если нет флага минус, то нужно вначале поставить пробелы
  while (!flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}

void char_record_flags_after_func(config *flags, int *len_for_flags, char *str,
                                  int *j) {
  while (flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}
void main_char_record_to_str_func(char *str, va_list *vl, int *j,
                                  config *flags) {
  int ch = 0;
  ch = va_arg(*vl, int);
  int len_for_flags = 0;
  char_len_for_flags_func(flags, &len_for_flags);
  char_record_flags_before_func(flags, &len_for_flags, str, j);
  str[*j] = ch;
  (*j)++;
  char_record_flags_after_func(flags, &len_for_flags, str, j);
}
//получает указатель на строку из аргументов
void string_set_func(char **src_str, va_list *vl) {
  *src_str = va_arg(*vl, char *);
}

void string_len_func(char *src_str, int *len_of_src_str, config *flags) {
  if (!flags->dot) {
    *len_of_src_str = s21_strlen(src_str);
  } else {
    int tmp_len = 0;
    tmp_len = s21_strlen(src_str);
    if (tmp_len > flags->accuracy)
      *len_of_src_str = flags->accuracy;
    else
      *len_of_src_str = tmp_len;
  }
}
void string_len_for_flags_func(config *flags, int len_of_src_str,
                               int *len_for_flags) {
  *len_for_flags = len_of_src_str;
  if (flags->width > *len_for_flags) {
    *len_for_flags = flags->width;
  }
  *len_for_flags = *len_for_flags - len_of_src_str;
}
//запись пробелов перед строкой
void string_record_flags_before_func(config *flags, int *len_for_flags,
                                     char *str, int *j) {
  while (!flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}
//функция записи строки в строку
void string_record_to_str_func(const char *src_str, char *str,
                               int len_of_src_str, config *flags) {
  int i = 0;
  while ((src_str[i] != 0 && !flags->dot) || (flags->accuracy > 0)) {
    str[len_of_src_str] = src_str[i];
    len_of_src_str++;
    i++;
    flags->accuracy--;
  }
}
//если флаг минус, пробелы после строки
void string_record_flags_after_func(config *flags, int *len_for_flags,
                                    char *str, int *j) {
  while (flags->minus && *len_for_flags > 0) {
    str[*j] = ' ';
    (*j)++;
    (*len_for_flags)--;
  }
}

void string_record_null_func(char *str, int *j) {
  str[*j] = '(';
  (*j)++;
  str[*j] = 'n';
  (*j)++;
  str[*j] = 'u';
  (*j)++;
  str[*j] = 'l';
  (*j)++;
  str[*j] = 'l';
  (*j)++;
  str[*j] = ')';
  (*j)++;
}

void main_string_record_to_str_func(char *str, va_list *vl, int *j,
                                    config *flags) {
  char *src_str = s21_NULL;
  int len_of_src_str = 0;
  int len_for_flags = 0;
  string_set_func(&src_str, vl);
  if (src_str != s21_NULL) {
    string_len_func(src_str, &len_of_src_str, flags);
    string_len_for_flags_func(flags, len_of_src_str, &len_for_flags);
    string_record_flags_before_func(flags, &len_for_flags, str, j);
    string_record_to_str_func(src_str, str, *j, flags);
    *j = *j + len_of_src_str;
    string_record_flags_after_func(flags, &len_for_flags, str, j);
  } else {
    string_record_null_func(str, j);
  }
}

void main_percent_record_to_str_func(char *str, int *j) {
  str[*j] = '%';
  (*j)++;
}

//устанавливает систему счисления
void set_number_base_func(const char *format, int i, config *flags) {
  flags->number_base = 10;
  if (format[i] == 'o')
    flags->number_base = 8;
  else if (format[i] == 'x' || format[i] == 'X')
    flags->number_base = 16;
  if (format[i] == 'X' || format[i] == 'F') flags->up_case = true;
}

//функция выбора, что будет записано в строку, в зависимости от спецификатора
void specifier_selection_func(char *str, const char *format, int *i, int *j,
                              va_list *vl, config *flags) {
  set_number_base_func(format, *i, flags);
  if (format[*i] == 'd' || format[*i] == 'i') {
    main_decimal_record_to_str_func(str, vl, j, flags);
  } else if (format[*i] == 'u' || format[*i] == 'o' || format[*i] == 'x' ||
             format[*i] == 'X') {
    main_unsigned_record_to_str_func(str, vl, j, flags);
  } else if (format[*i] == 'f' || format[*i] == 'F') {
    main_double_record_to_str_func(str, vl, j, flags);
  } else if (format[*i] == 'c') {
    main_char_record_to_str_func(str, vl, j, flags);
  } else if (format[*i] == 's') {
    main_string_record_to_str_func(str, vl, j, flags);
  } else if (format[*i] == '%') {
    main_percent_record_to_str_func(str, j);
  } else
    flags->format_error = true;
  if (format[*i] != '\0' && !flags->format_error) *i = *i + 1;
}
//парсер первой части флагов, без ширины,точности и длины
void flags_parser_func(int *i, const char *format, config *flags) {
  bool stop = true;
  while (stop) {
    switch (format[*i]) {
      case '+':
        flags->plus = true;
        (*i)++;
        break;
      case '-':
        flags->minus = true;
        (*i)++;
        break;
      case '#':
        flags->hash = true;
        (*i)++;
        break;
      case ' ':
        flags->space = true;
        (*i)++;
        break;
      case '0':
        flags->zero = true;
        flags->dzero = true;
        (*i)++;
        break;
      default:
        stop = false;
    }
  }
  if (flags->space && flags->plus) flags->space = false;
  if (flags->zero && flags->minus) flags->zero = false;
}
//парсер ширины и точности
void set_width_accuracy_func(int *i, const char *format, int *precision,
                             va_list *vl) {
  if (format[*i] == '*') {
    *precision = va_arg(*vl, int);
    *i = *i + 1;
  }
  for (;; (*i)++) {
    if ('0' <= format[*i] && format[*i] <= '9') {
      *precision = *precision * 10;
      *precision = *precision + (format[*i] - '0');
    } else {
      break;
    }
  }
}

//парсер длинны, если задана
void set_length_parser(int *i, const char *format, config *flags) {
  if (format[*i] == 'L')
    flags->length = 'L';
  else if (format[*i] == 'l')
    flags->length = 'l';
  else if (format[*i] == 'h')
    flags->length = 'h';
  if (flags->length != 0) (*i)++;
}

//общий парсер
void general_parser_func(int *i, const char *format, config *flags,
                         va_list *vl) {
  flags_parser_func(i, format, flags);
  set_width_accuracy_func(i, format, &flags->width, vl);
  if (format[*i] == '.') {
    (*i)++;
    flags->dot = true;
    flags->zero = false;
    set_width_accuracy_func(i, format, &flags->accuracy, vl);
  }
  set_length_parser(i, format, flags);
  if (flags->width < 0) {
    flags->width = -flags->width;
    flags->minus = true;
  }
}

int func_for_special(char *str, const char *format, int *i, int *j,
                     va_list *vl) {
  config flags = {0};
  int src_i = *i;  // вернуть изначальный i если ошибка в форматной строке
  int error_len = 0;
  (*i)++;
  general_parser_func(i, format, &flags, vl);
  specifier_selection_func(str, format, i, j, vl, &flags);
  if (flags.format_error) {
    error_len = *i - src_i;
    *i = src_i;
  }
  return error_len;
}

int main_cycle_func(char *str, const char *format, va_list *vl) {
  int j = 0;
  int i = 0;
  int error_len = 0;  //флаг если форматная строка с ошибкой
  int main_flag = 0;
  while (format[i]) {
    if (format[i] == '%' && !error_len) {
      if (!format[i + 1]) {
        main_flag = 1;
        break;
      }
      error_len = func_for_special(str, format, &i, &j, vl);
      if (error_len != 0) main_flag = 1;
    } else {
      str[j] = format[i];
      i++;
      j++;
      if (error_len > 0) error_len--;
    }
  }
  str[j] = '\0';
  if (main_flag) j = -1;
  return j;
}

int s21_sprintf(char *str, const char *format, ...) {
  int result = 0;
  va_list vl;
  va_start(vl, format);
  result = main_cycle_func(str, format, &vl);
  va_end(vl);
  return result;
}
