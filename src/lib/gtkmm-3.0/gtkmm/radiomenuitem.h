// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_RADIOMENUITEM_H
#define _GTKMM_RADIOMENUITEM_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: radiomenuitem.hg,v 1.7 2005/04/07 08:46:44 murrayc Exp $ */

/* radiomenuitem.h
 * 
 * Copyright (C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtkmm/checkmenuitem.h>
#include <gtkmm/radiobutton.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkRadioMenuItem GtkRadioMenuItem;
typedef struct _GtkRadioMenuItemClass GtkRadioMenuItemClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class RadioMenuItem_Class; } // namespace Gtk
namespace Gtk
{

class RadioMenuItem;

/** A CheckMenuItem that belongs to a group.
 * At each instant exactly one of the menu items from a group is selected.
 * @ingroup Menus
 * @ingroup Widgets
 */

class RadioMenuItem : public CheckMenuItem
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef RadioMenuItem CppObjectType;
  typedef RadioMenuItem_Class CppClassType;
  typedef GtkRadioMenuItem BaseObjectType;
  typedef GtkRadioMenuItemClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~RadioMenuItem();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class RadioMenuItem_Class;
  static CppClassType radiomenuitem_class_;

  // noncopyable
  RadioMenuItem(const RadioMenuItem&);
  RadioMenuItem& operator=(const RadioMenuItem&);

protected:
  explicit RadioMenuItem(const Glib::ConstructParams& construct_params);
  explicit RadioMenuItem(GtkRadioMenuItem* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkRadioMenuItem*       gobj()       { return reinterpret_cast<GtkRadioMenuItem*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkRadioMenuItem* gobj() const { return reinterpret_cast<GtkRadioMenuItem*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_group_changed().
  virtual void on_group_changed();


private:

public:
  
  typedef RadioButtonGroup Group;

  RadioMenuItem(Group& groupx);
  
  RadioMenuItem(Group& groupx, const Glib::ustring& label, bool mnemonic = false);
  

  //We ignore the _new_*_from_widget() functions because they are just the same as calling get_group() and set_group() ourselves.
  
                    
  /** Returns the group to which the radio menu item belongs, as a List of
   * Gtk::RadioMenuItem. The list belongs to GTK+ and should not be freed.
   * @return The group
   * of @a radio_menu_item.
   */
  Group get_group();
  
  void set_group(Group& group);
  void reset_group();

  /** Emitted when the group of radio menu items that a radio menu item belongs
   * to changes. This is emitted when a radio menu item switches from
   * being alone to being part of a group of 2 or more menu items, or
   * vice-versa, and when a buttton is moved from one group of 2 or
   * more menu items to a different one, but not when the composition
   * of the group that a menu item belongs to changes.
   *
* @par Slot Prototype:
   * <tt>void on_my_%group_changed()</tt>
   *
   */

  Glib::SignalProxy0< void > signal_group_changed();


  //Probably wouldn't work: _WRAP_PROPERTY("group", Group)

protected:
  void constructor(const Group& group);


};

} /* namspace Gtk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::RadioMenuItem
   */
  Gtk::RadioMenuItem* wrap(GtkRadioMenuItem* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_RADIOMENUITEM_H */

