// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_MENUSHELL_H
#define _GTKMM_MENUSHELL_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* $Id: menushell.hg,v 1.9 2006/06/21 20:04:25 murrayc Exp $ */

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gdk/gdkkeysyms.h>


#include <gtkmm/container.h>
#include <gtkmm/menuitem.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkMenuShell GtkMenuShell;
typedef struct _GtkMenuShellClass GtkMenuShellClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class MenuShell_Class; } // namespace Gtk
namespace Gtk
{

class Menu;
class Window;


/** The abstract base class for Gtk::Menu and Gtk::MenuBar.
 * It is a container of Gtk::MenuItem objects arranged in a list which can be navigated, selected, and activated by the user to perform application functions.
 * It can have a submenu associated with it, allowing for nested hierarchical menus.
 * Use append(), prepend() and insert() to add Gtk::MenuItem widgets.
 * @ingroup Widgets
 * @ingroup Containers
 * @ingroup Menus
 */

class MenuShell : public Container
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MenuShell CppObjectType;
  typedef MenuShell_Class CppClassType;
  typedef GtkMenuShell BaseObjectType;
  typedef GtkMenuShellClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~MenuShell();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class MenuShell_Class;
  static CppClassType menushell_class_;

  // noncopyable
  MenuShell(const MenuShell&);
  MenuShell& operator=(const MenuShell&);

protected:
  explicit MenuShell(const Glib::ConstructParams& construct_params);
  explicit MenuShell(GtkMenuShell* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkMenuShell*       gobj()       { return reinterpret_cast<GtkMenuShell*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkMenuShell* gobj() const { return reinterpret_cast<GtkMenuShell*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_deactivate().
  virtual void on_deactivate();
  /// This is a default handler for the signal signal_selection_done().
  virtual void on_selection_done();
  /// This is a default handler for the signal signal_move_selected().
  virtual gboolean on_move_selected(int distance);


private:


public:
  

  /** Adds a new Gtk::MenuItem to the end of the menu shell's
   * item list.
   * @param child The Gtk::MenuItem to add.
   */
  void append(MenuItem& menu_item);
  
  /** Adds a new Gtk::MenuItem to the beginning of the menu shell's
   * item list.
   * @param child The Gtk::MenuItem to add.
   */
  void prepend(MenuItem& menu_item);
  
  /** Adds a new Gtk::MenuItem to the menu shell's item list
   * at the position indicated by @a position.
   * @param child The Gtk::MenuItem to add.
   * @param position The position in the item list where @a child
   * is added. Positions are numbered from 0 to n-1.
   */
  void insert(MenuItem& menu_item, int position);

  
  /** Selects the menu item from the menu shell.
   * @param menu_item The Gtk::MenuItem to select.
   */
  void select_item(MenuItem& menu_item);
  
  /** Deselects the currently selected item from the menu shell,
   * if any.
   */
  void deselect();

  //TODO: Is force_deactivate = false a good default?
  
  /** Activates the menu item within the menu shell.
   * @param menu_item The Gtk::MenuItem to activate.
   * @param force_deactivate If <tt>true</tt>, force the deactivation of the
   * menu shell after the menu item is activated.
   */
  void activate_item(MenuItem& menu_item, bool force_deactivate =  false);
  
  /** Select the first visible or selectable child of the menu shell;
   * don't select tearoff items unless the only item is a tearoff
   * item.
   * 
   * @newin{2,2}
   * @param search_sensitive If <tt>true</tt>, search for the first selectable
   * menu item, otherwise select nothing if
   * the first item isn't sensitive. This
   * should be <tt>false</tt> if the menu is being
   * popped up initially.
   */
  void select_first(bool search_sensitive =  true);
  
  /** Deactivates the menu shell.
   * 
   * Typically this results in the menu shell being erased
   * from the screen.
   */
  void deactivate();
  
  /** Cancels the selection within the menu shell.
   * 
   * @newin{2,4}
   */
  void cancel();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%deactivate()</tt>
   *
   * This signal is emitted when a menu shell is deactivated.
   */

  Glib::SignalProxy0< void > signal_deactivate();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%selection_done()</tt>
   *
   * This signal is emitted when a selection has been
   * completed within a menu shell.
   */

  Glib::SignalProxy0< void > signal_selection_done();

  
/**
   * @par Slot Prototype:
   * <tt>gboolean on_my_%move_selected(int distance)</tt>
   *
   * The signal_move_selected() signal is emitted to move the selection to
   * another item.
   * 
   * @newin{2,12}
   * @param distance +1 to move to the next item, -1 to move to the previous.
   * @return <tt>true</tt> to stop the signal emission, <tt>false</tt> to continue.
   */

  Glib::SignalProxy1< gboolean,int > signal_move_selected();


  //TODO: Remove no_default_handler when we can break ABI.
  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%insert(Widget* child, int position)</tt>
   *
   * The signal_insert() signal is emitted when a new Gtk::MenuItem is added to
   * a Gtk::MenuShell.  A separate signal is used instead of
   * GtkContainer::add because of the need for an additional position
   * parameter.
   * 
   * The inverse of this signal is the GtkContainer::removed signal.
   * 
   * @newin{3,2}
   * @param child The Gtk::MenuItem that is being inserted.
   * @param position The position at which the insert occurs.
   */

  Glib::SignalProxy2< void,Widget*,int > signal_insert();


  //Keybinding signals:
  
  
  /**
   * Initializes menu accelerators.
   * This method initializes the menu accelerators. Therefore an
   * AccelGroup object is needed which is stored in each Window object
   * in the Gtkmm library implementation.
   *
   * When using MenuBar and OptionMenu objects this method is called
   * automatically when the menus are realized. Because most likely the
   * MenuBar and OptionMenu is attached to a window at this time and
   * the window object can be found automatically.
   *
   * Important note when using popup menus:
   * If you are using accelerated menu entries inside a popup
   * menu you have to call the accelerate() method manually. This is
   * because the popup menu is not connected to any window and the
   * accelerators should be initialized even before the popup menu is
   * shown. The right place to call the accelerate() method is right
   * after the popup menu has been build.
   *
   * @param window Window where the menu is shown. Inside this window
   *   the AccelGroup object is stored that will be used to initialize
   *   the accelerators.
   */
  void accelerate(Window& window);

  /**
   * Initializes menu accelerators.
   * Does the same as the accelerate(Window& window) method. But you can
   * use any parent widget where the menu is used. This method then gets
   * the toplevel window using Widget::get_toplevel() and uses this
   * window for registering the menu accelerators.
   *
   * @param parent Parent widget used as starting point for searching
   *   the toplevel window.
   */
  void accelerate(Widget& parent);

  
  /** Returns <tt>true</tt> if the menu shell will take the keyboard focus on popup.
   * 
   * @newin{2,8}
   * @return <tt>true</tt> if the menu shell will take the keyboard focus on popup.
   */
  bool get_take_focus() const;
  
  /** If @a take_focus is <tt>true</tt> (the default) the menu shell will take
   * the keyboard focus so that it will receive all keyboard events
   * which is needed to enable keyboard navigation in menus.
   * 
   * Setting @a take_focus to <tt>false</tt> is useful only for special applications
   * like virtual keyboard implementations which should not take keyboard
   * focus.
   * 
   * The @a take_focus state of a menu or menu bar is automatically
   * propagated to submenus whenever a submenu is popped up, so you
   * don't have to worry about recursively setting it for your entire
   * menu hierarchy. Only when programmatically picking a submenu and
   * popping it up manually, the @a take_focus property of the submenu
   * needs to be set explicitely.
   * 
   * Note that setting it to <tt>false</tt> has side-effects:
   * 
   * If the focus is in some other app, it keeps the focus and keynav in
   * the menu doesn't work. Consequently, keynav on the menu will only
   * work if the focus is on some toplevel owned by the onscreen keyboard.
   * 
   * To avoid confusing the user, menus with @a take_focus set to <tt>false</tt>
   * should not display mnemonics or accelerators, since it cannot be
   * guaranteed that they will work.
   * 
   * See also gdk_keyboard_grab()
   * 
   * @newin{2,8}
   * @param take_focus <tt>true</tt> if the menu shell should take the keyboard
   * focus on popup.
   */
  void set_take_focus(bool take_focus =  true);
  
  
  /** Gets the currently selected item.
   * 
   * @newin{3,0}
   * @return The currently selected item.
   */
  Widget* get_selected_item();
  
  /** Gets the currently selected item.
   * 
   * @newin{3,0}
   * @return The currently selected item.
   */
  const Widget* get_selected_item() const;
  
  
  /** Gets the parent menu shell.
   * 
   * The parent menu shell of a submenu is the Gtk::Menu or Gtk::MenuBar
   * from which it was opened up.
   * 
   * @newin{3,0}
   * @return The parent Gtk::MenuShell.
   */
  Widget* get_parent_shell();
  
  /** Gets the parent menu shell.
   * 
   * The parent menu shell of a submenu is the Gtk::Menu or Gtk::MenuBar
   * from which it was opened up.
   * 
   * @newin{3,0}
   * @return The parent Gtk::MenuShell.
   */
  const Widget* get_parent_shell() const;
  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** A boolean that determines whether the menu grabs the keyboard focus.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_take_focus() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** A boolean that determines whether the menu grabs the keyboard focus.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_take_focus() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


protected:
  MenuShell();
  

private:


  Gtk::Window*  accel_window_;


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::MenuShell
   */
  Gtk::MenuShell* wrap(GtkMenuShell* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_MENUSHELL_H */

