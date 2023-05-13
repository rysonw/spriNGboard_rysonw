/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef cmCursesColor_h
#define cmCursesColor_h

class cmCursesColor
{
public:
  enum Color
  {
    // Default color is pair 0
    BoolOff = 1,
    BoolOn,
    String,
    Path,
    Choice
  };

  static bool HasColors();

  static void InitColors();

protected:
  static short GetColor(char id, short fallback);
};

#endif // cmCursesColor_h
