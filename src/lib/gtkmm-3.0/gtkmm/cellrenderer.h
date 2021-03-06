// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_CELLRENDERER_H
#define _GTKMM_CELLRENDERER_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

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


#include <gtkmm/widget.h>
#include <gtkmm/celleditable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkCellRenderer GtkCellRenderer;
typedef struct _GtkCellRendererClass GtkCellRendererClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class CellRenderer_Class; } // namespace Gtk
namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%CellRendererState operator|(CellRendererState, CellRendererState)</tt><br>
 * <tt>%CellRendererState operator&(CellRendererState, CellRendererState)</tt><br>
 * <tt>%CellRendererState operator^(CellRendererState, CellRendererState)</tt><br>
 * <tt>%CellRendererState operator~(CellRendererState)</tt><br>
 * <tt>%CellRendererState& operator|=(CellRendererState&, CellRendererState)</tt><br>
 * <tt>%CellRendererState& operator&=(CellRendererState&, CellRendererState)</tt><br>
 * <tt>%CellRendererState& operator^=(CellRendererState&, CellRendererState)</tt><br>
 */
enum CellRendererState
{
  CELL_RENDERER_SELECTED = 1 << 0,
  CELL_RENDERER_PRELIT = 1 << 1,
  CELL_RENDERER_INSENSITIVE = 1 << 2,
  CELL_RENDERER_SORTED = 1 << 3,
  CELL_RENDERER_FOCUSED = 1 << 4,
  CELL_RENDERER_EXPANDABLE = 1 << 5,
  CELL_RENDERER_EXPANDED = 1 << 6
};

/** @ingroup gtkmmEnums */
inline CellRendererState operator|(CellRendererState lhs, CellRendererState rhs)
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline CellRendererState operator&(CellRendererState lhs, CellRendererState rhs)
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline CellRendererState operator^(CellRendererState lhs, CellRendererState rhs)
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline CellRendererState operator~(CellRendererState flags)
  { return static_cast<CellRendererState>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline CellRendererState& operator|=(CellRendererState& lhs, CellRendererState rhs)
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline CellRendererState& operator&=(CellRendererState& lhs, CellRendererState rhs)
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline CellRendererState& operator^=(CellRendererState& lhs, CellRendererState rhs)
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::CellRendererState> : public Glib::Value_Flags<Gtk::CellRendererState>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{

/**
 * @ingroup gtkmmEnums
 */
enum CellRendererMode
{
  CELL_RENDERER_MODE_INERT,
  CELL_RENDERER_MODE_ACTIVATABLE,
  CELL_RENDERER_MODE_EDITABLE
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::CellRendererMode> : public Glib::Value_Enum<Gtk::CellRendererMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** CellRenderers are used by Gtk::TreeView columns to render the Gtk::TreeModel column data appropriately.
 * They display, and allow editing of, the values of their properties.
 * In most cases, Gtk::TreeView::append_column() will automatically choose the appropriate renderer for the mode column's data type,
 * so you will rarely need to worry about these classes.
 *
 * @ingroup TreeView
 */

class CellRenderer :
  public Object
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRenderer CppObjectType;
  typedef CellRenderer_Class CppClassType;
  typedef GtkCellRenderer BaseObjectType;
  typedef GtkCellRendererClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~CellRenderer();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class CellRenderer_Class;
  static CppClassType cellrenderer_class_;

  // noncopyable
  CellRenderer(const CellRenderer&);
  CellRenderer& operator=(const CellRenderer&);

protected:
  explicit CellRenderer(const Glib::ConstructParams& construct_params);
  explicit CellRenderer(GtkCellRenderer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkCellRenderer*       gobj()       { return reinterpret_cast<GtkCellRenderer*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkCellRenderer* gobj() const { return reinterpret_cast<GtkCellRenderer*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_editing_canceled().
  virtual void on_editing_canceled();
  /// This is a default handler for the signal signal_editing_started().
  virtual void on_editing_started(CellEditable* editable, const Glib::ustring& path);


private:

public:

   //Deprecated

  
  /** Gets whether the cell renderer prefers a height-for-width layout
   * or a width-for-height layout.
   * 
   * @newin{3,0}
   * @return The Gtk::SizeRequestMode preferred by this renderer.
   */
  SizeRequestMode get_request_mode() const;
  
  /** Retreives a renderer's natural size when rendered to @a widget.
   * 
   * @newin{3,0}
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param minimum_size Location to store the minimum size, or <tt>0</tt>.
   * @param natural_size Location to store the natural size, or <tt>0</tt>.
   */
  void get_preferred_width(Widget& widget, int& minimum_width, int& natural_width) const;
  
  /** Retreives a cell renderers's minimum and natural height if it were rendered to 
   *  @a widget with the specified @a width.
   * 
   * @newin{3,0}
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param width The size which is available for allocation.
   * @param minimum_height Location for storing the minimum size, or <tt>0</tt>.
   * @param natural_height Location for storing the preferred size, or <tt>0</tt>.
   */
  void get_preferred_height_for_width(Widget& widget, int width, int& minimum_height, int& natural_height) const;
  
  /** Retreives a renderer's natural size when rendered to @a widget.
   * 
   * @newin{3,0}
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param minimum_size Location to store the minimum size, or <tt>0</tt>.
   * @param natural_size Location to store the natural size, or <tt>0</tt>.
   */
  void get_preferred_height(Widget& widget, int& minimum_height, int& natural_height) const;
  
  /** Retreives a cell renderers's minimum and natural width if it were rendered to 
   *  @a widget with the specified @a height.
   * 
   * @newin{3,0}
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param height The size which is available for allocation.
   * @param minimum_width Location for storing the minimum size, or <tt>0</tt>.
   * @param natural_width Location for storing the preferred size, or <tt>0</tt>.
   */
  void get_preferred_width_for_height(Widget& widget, int height, int& minimum_width, int& natural_width) const;
  
  /** Retrieves the minimum and natural size of a cell taking
   * into account the widget's preference for height-for-width management.
   * 
   * @newin{3,0}
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param minimum_size Location for storing the minimum size, or <tt>0</tt>.
   * @param natural_size Location for storing the natural size, or <tt>0</tt>.
   */
  void get_preferred_size(Widget& widget, Requisition& minimum_size, Requisition& natural_size) const;
  
  //TODO: Use a return value intead?
  
  /** Gets the aligned area used by @a cell inside @a cell_area. Used for finding
   * the appropriate edit and focus rectangle.
   * 
   * @newin{3,0}
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param flags Render flags.
   * @param cell_area Cell area which would be passed to render().
   * @param aligned_area The return location for the space inside @a cell_area
   * that would acually be used to render.
   */
  void get_aligned_area(Widget& widget, CellRendererState flags, const Gdk::Rectangle& cell_area, Gdk::Rectangle& aligned_area);

  
  /** Invokes the virtual render function of the Gtk::CellRenderer. The three
   * passed-in rectangles are areas in @a cr. Most renderers will draw within
   *  @a cell_area; the xalign, yalign, xpad, and ypad fields of the Gtk::CellRenderer
   * should be honored with respect to @a cell_area. @a background_area includes the
   * blank space around the cell, and also the area containing the tree expander;
   * so the @a background_area rectangles for all cells tile to cover the entire
   *  @a window.
   * @param cr A cairo context to draw to.
   * @param widget The widget owning @a window.
   * @param background_area Entire cell area (including tree expanders and maybe 
   * padding on the sides).
   * @param cell_area Area normally rendered by a cell renderer.
   * @param flags Flags that affect rendering.
   */
  void render(const ::Cairo::RefPtr< ::Cairo::Context>& cr, Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);

  
  /** Passes an activate event to the cell renderer for possible processing.  
   * Some cell renderers may use events; for example, Gtk::CellRendererToggle 
   * toggles when it gets a mouse click.
   * @param event A Gdk::Event.
   * @param widget Widget that received the event.
   * @param path Widget-dependent string representation of the event location; 
   * e.g. for Gtk::TreeView, a string representation of Gtk::TreePath.
   * @param background_area Background area as passed to render().
   * @param cell_area Cell area as passed to render().
   * @param flags Render flags.
   * @return <tt>true</tt> if the event was consumed/handled.
   */
  bool activate(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);

  
  /** Passes an activate event to the cell renderer for possible processing.
   * @param event A Gdk::Event.
   * @param widget Widget that received the event.
   * @param path Widget-dependent string representation of the event location;
   * e.g. for Gtk::TreeView, a string representation of Gtk::TreePath.
   * @param background_area Background area as passed to render().
   * @param cell_area Cell area as passed to render().
   * @param flags Render flags.
   * @return A new Gtk::CellEditable, or <tt>0</tt>.
   */
  CellEditable* start_editing(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags =  CellRendererState(0));

  
  /** Sets the renderer size to be explicit, independent of the properties set.
   * @param width The width of the cell renderer, or -1.
   * @param height The height of the cell renderer, or -1.
   */
  void set_fixed_size(int width, int height);
  
  /** Fills in @a width and @a height with the appropriate size of @a cell.
   * @param width Location to fill in with the fixed width of the widget.
   * @param height Location to fill in with the fixed height of the widget.
   */
  void get_fixed_size(int& width, int& height) const;

   //deprecated

  
  /** Sets the renderer's alignment within its available space.
   * 
   * @newin{2,18}
   * @param xalign The x alignment of the cell renderer.
   * @param yalign The y alignment of the cell renderer.
   */
  void set_alignment(float align, float yalign);
  
  /** Fills in @a xalign and @a yalign with the appropriate values of @a cell.
   * 
   * @newin{2,18}
   * @param xalign Location to fill in with the x alignment of the cell, or <tt>0</tt>.
   * @param yalign Location to fill in with the y alignment of the cell, or <tt>0</tt>.
   */
  void get_alignment(float& xalign, float& yalign) const;

  
  /** Sets the renderer's padding.
   * 
   * @newin{2,18}
   * @param xpad The x padding of the cell renderer.
   * @param ypad The y padding of the cell renderer.
   */
  void set_padding(int xpad, int ypad);
  
  /** Fills in @a xpad and @a ypad with the appropriate values of @a cell.
   * 
   * @newin{2,18}
   * @param xpad Location to fill in with the x padding of the cell, or <tt>0</tt>.
   * @param ypad Location to fill in with the y padding of the cell, or <tt>0</tt>.
   */
  void get_padding(int& xpad, int& ypad) const;

  
  /** Sets the cell renderer's visibility.
   * 
   * @newin{2,18}
   * @param visible The visibility of the cell.
   */
  void set_visible(bool visible =  true);
  
  /** Returns the cell renderer's visibility.
   * 
   * @newin{2,18}
   * @return <tt>true</tt> if the cell renderer is visible.
   */
  bool get_visible() const;
  
  /** Sets the cell renderer's sensitivity.
   * 
   * @newin{2,18}
   * @param sensitive The sensitivity of the cell.
   */
  void set_sensitive(bool sensitive =  true);
  
  /** Returns the cell renderer's sensitivity.
   * 
   * @newin{2,18}
   * @return <tt>true</tt> if the cell renderer is sensitive.
   */
  bool get_sensitive() const;
  
  /** Checks whether the cell renderer can do something when activated.
   * 
   * @newin{3,0}
   * @return <tt>true</tt> if the cell renderer can do anything when activated.
   */
  bool is_activatable() const;

  
  /** Informs the cell renderer that the editing is stopped.
   * If @a canceled is <tt>true</tt>, the cell renderer will emit the 
   * Gtk::CellRenderer::signal_editing_canceled() signal. 
   * 
   * This function should be called by cell renderer implementations 
   * in response to the Gtk::CellEditable::signal_editing_done() signal of 
   * Gtk::CellEditable.
   * 
   * @newin{2,6}
   * @param canceled <tt>true</tt> if the editing has been canceled.
   */
  void stop_editing(bool canceled =  false);
  
  
  /** Translates the cell renderer state to Gtk::StateFlags,
   * based on the cell renderer and widget sensitivity, and
   * the given Gtk::CellRendererState.
   * 
   * @newin{3,0}
   * @param widget A Gtk::Widget, or <tt>0</tt>.
   * @param cell_state Cell renderer state.
   * @return The widget state flags applying to @a cell.
   */
  StateFlags get_state(Widget& widget, CellRendererState cell_state) const;
  
  
  /** Translates the cell renderer state to StateFlags,
   * based on the cell renderer and
   * the given CellRendererState.
   *
   * @param cell_state The cell renderer state.
   *
   * @result The widget state flags applying to the cell renderer.
   *
   * @newin{3,0}
   */
  StateFlags get_state(CellRendererState cell_state) const;

  /** Returns the property that this CellRenderer renders.
   * For instance, property_text for CellRendererText, and property_active for CellRendererToggle
   * Needs to be overridden in derived classes.
   */
  virtual Glib::PropertyProxy_Base _property_renderable();

  
/**
   * @par Slot Prototype:
   * <tt>void on_my_%editing_canceled()</tt>
   *
   * This signal gets emitted when the user cancels the process of editing a
   * cell.  For example, an editable cell renderer could be written to cancel
   * editing when the user presses Escape. 
   * 
   * See also: Gtk::CellRenderer::stop_editing().
   * 
   * @newin{2,4}
   */

  Glib::SignalProxy0< void > signal_editing_canceled();


  //TODO: Remove the warning in the documentation when we have fixed the
  //inheritance of CellRendererCombo.
  /** Note that this signal does not work yet in gtkmm.
   * See http://bugzilla.gnome.org/show_bug.cgi?id=301597
   *
* @par Slot Prototype:
   * <tt>void on_my_%editing_started(CellEditable* editable, const Glib::ustring& path)</tt>
   *
   * This signal gets emitted when a cell starts to be edited.
   * The intended use of this signal is to do special setup
   * on @a editable, e.g. adding a Gtk::EntryCompletion or setting
   * up additional columns in a Gtk::ComboBox.
   * 
   * Note that GTK+ doesn't guarantee that cell renderers will
   * continue to use the same kind of widget for editing in future
   * releases, therefore you should check the type of @a editable
   * before doing any specific setup, as in the following example:
   * 
   * [C example ellipted]
   * 
   * @newin{2,6}
   * @param editable The Gtk::CellEditable.
   * @param path The path identifying the edited cell.
   */

  Glib::SignalProxy2< void,CellEditable*,const Glib::ustring& > signal_editing_started();


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Editable mode of the CellRenderer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< CellRendererMode > property_mode() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Editable mode of the CellRenderer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< CellRendererMode > property_mode() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Display the cell.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_visible() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Display the cell.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_visible() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Display the cell sensitive.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_sensitive() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Display the cell sensitive.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_sensitive() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The x-align.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< float > property_xalign() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The x-align.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< float > property_xalign() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The y-align.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< float > property_yalign() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The y-align.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< float > property_yalign() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The xpad.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< unsigned int > property_xpad() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The xpad.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< unsigned int > property_xpad() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The ypad.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< unsigned int > property_ypad() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The ypad.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< unsigned int > property_ypad() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The fixed width.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< int > property_width() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The fixed width.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_width() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The fixed height.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< int > property_height() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The fixed height.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_height() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Row has children.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_is_expander() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Row has children.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_is_expander() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Row is an expander row, and is expanded.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_is_expanded() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Row is an expander row, and is expanded.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_is_expanded() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Cell background color as a string.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_WriteOnly< Glib::ustring > property_cell_background() ;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Cell background color as a GdkColor.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Gdk::Color > property_cell_background_gdk() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Cell background color as a GdkColor.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::Color > property_cell_background_gdk() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Cell background color as a GdkRGBA.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Gdk::RGBA > property_cell_background_rgba() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Cell background color as a GdkRGBA.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::RGBA > property_cell_background_rgba() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether this tag affects the cell background color.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_cell_background_set() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether this tag affects the cell background color.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_cell_background_set() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the cell renderer is currently in editing mode.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_editing() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


protected:
  CellRenderer();


    virtual SizeRequestMode get_request_mode_vfunc() const;

    virtual void get_preferred_width_vfunc(Widget& widget, int& minimum_width, int& natural_width) const;

    virtual void get_preferred_height_for_width_vfunc(Widget& widget, int width, int& minimum_height, int& natural_height) const;

    virtual void get_preferred_height_vfunc(Widget& widget, int& minimum_height, int& natural_height) const;

    virtual void get_preferred_width_for_height_vfunc(Widget& widget, int height, int& minimum_width, int& natural_width) const;


    virtual void render_vfunc(const ::Cairo::RefPtr< ::Cairo::Context>& cr, Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


    virtual bool activate_vfunc(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


    virtual CellEditable* start_editing_vfunc(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


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
   * @relates Gtk::CellRenderer
   */
  Gtk::CellRenderer* wrap(GtkCellRenderer* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_CELLRENDERER_H */

