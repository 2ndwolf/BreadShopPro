// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_test_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsGaniInformation_SpriteDefImpl();
void InitDefaultsGaniInformation_SpriteDef();
void InitDefaultsGaniInformationImpl();
void InitDefaultsGaniInformation();
inline void InitDefaults() {
  InitDefaultsGaniInformation_SpriteDef();
  InitDefaultsGaniInformation();
}
}  // namespace protobuf_test_2eproto
class GaniInformation;
class GaniInformationDefaultTypeInternal;
extern GaniInformationDefaultTypeInternal _GaniInformation_default_instance_;
class GaniInformation_SpriteDef;
class GaniInformation_SpriteDefDefaultTypeInternal;
extern GaniInformation_SpriteDefDefaultTypeInternal _GaniInformation_SpriteDef_default_instance_;

enum GaniInformation_SpriteDef_DefaultImageType {
  GaniInformation_SpriteDef_DefaultImageType_NOTDEFAULT = 0,
  GaniInformation_SpriteDef_DefaultImageType_SPRITES = 1,
  GaniInformation_SpriteDef_DefaultImageType_SHIELD = 2,
  GaniInformation_SpriteDef_DefaultImageType_HEAD = 3,
  GaniInformation_SpriteDef_DefaultImageType_BODY = 4,
  GaniInformation_SpriteDef_DefaultImageType_SWORD = 5,
  GaniInformation_SpriteDef_DefaultImageType_HORSE = 6,
  GaniInformation_SpriteDef_DefaultImageType_PARAM1 = 7,
  GaniInformation_SpriteDef_DefaultImageType_ATTR1 = 8,
  GaniInformation_SpriteDef_DefaultImageType_PARAM2 = 9,
  GaniInformation_SpriteDef_DefaultImageType_ATTR2 = 10,
  GaniInformation_SpriteDef_DefaultImageType_PARAM3 = 11,
  GaniInformation_SpriteDef_DefaultImageType_ATTR3 = 12
};
bool GaniInformation_SpriteDef_DefaultImageType_IsValid(int value);
const GaniInformation_SpriteDef_DefaultImageType GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_MIN = GaniInformation_SpriteDef_DefaultImageType_NOTDEFAULT;
const GaniInformation_SpriteDef_DefaultImageType GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_MAX = GaniInformation_SpriteDef_DefaultImageType_ATTR3;
const int GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_ARRAYSIZE = GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_MAX + 1;

const ::google::protobuf::EnumDescriptor* GaniInformation_SpriteDef_DefaultImageType_descriptor();
inline const ::std::string& GaniInformation_SpriteDef_DefaultImageType_Name(GaniInformation_SpriteDef_DefaultImageType value) {
  return ::google::protobuf::internal::NameOfEnum(
    GaniInformation_SpriteDef_DefaultImageType_descriptor(), value);
}
inline bool GaniInformation_SpriteDef_DefaultImageType_Parse(
    const ::std::string& name, GaniInformation_SpriteDef_DefaultImageType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<GaniInformation_SpriteDef_DefaultImageType>(
    GaniInformation_SpriteDef_DefaultImageType_descriptor(), name, value);
}
// ===================================================================

class GaniInformation_SpriteDef : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GaniInformation.SpriteDef) */ {
 public:
  GaniInformation_SpriteDef();
  virtual ~GaniInformation_SpriteDef();

  GaniInformation_SpriteDef(const GaniInformation_SpriteDef& from);

  inline GaniInformation_SpriteDef& operator=(const GaniInformation_SpriteDef& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GaniInformation_SpriteDef(GaniInformation_SpriteDef&& from) noexcept
    : GaniInformation_SpriteDef() {
    *this = ::std::move(from);
  }

  inline GaniInformation_SpriteDef& operator=(GaniInformation_SpriteDef&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GaniInformation_SpriteDef& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GaniInformation_SpriteDef* internal_default_instance() {
    return reinterpret_cast<const GaniInformation_SpriteDef*>(
               &_GaniInformation_SpriteDef_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(GaniInformation_SpriteDef* other);
  friend void swap(GaniInformation_SpriteDef& a, GaniInformation_SpriteDef& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GaniInformation_SpriteDef* New() const PROTOBUF_FINAL { return New(NULL); }

  GaniInformation_SpriteDef* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GaniInformation_SpriteDef& from);
  void MergeFrom(const GaniInformation_SpriteDef& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(GaniInformation_SpriteDef* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef GaniInformation_SpriteDef_DefaultImageType DefaultImageType;
  static const DefaultImageType NOTDEFAULT =
    GaniInformation_SpriteDef_DefaultImageType_NOTDEFAULT;
  static const DefaultImageType SPRITES =
    GaniInformation_SpriteDef_DefaultImageType_SPRITES;
  static const DefaultImageType SHIELD =
    GaniInformation_SpriteDef_DefaultImageType_SHIELD;
  static const DefaultImageType HEAD =
    GaniInformation_SpriteDef_DefaultImageType_HEAD;
  static const DefaultImageType BODY =
    GaniInformation_SpriteDef_DefaultImageType_BODY;
  static const DefaultImageType SWORD =
    GaniInformation_SpriteDef_DefaultImageType_SWORD;
  static const DefaultImageType HORSE =
    GaniInformation_SpriteDef_DefaultImageType_HORSE;
  static const DefaultImageType PARAM1 =
    GaniInformation_SpriteDef_DefaultImageType_PARAM1;
  static const DefaultImageType ATTR1 =
    GaniInformation_SpriteDef_DefaultImageType_ATTR1;
  static const DefaultImageType PARAM2 =
    GaniInformation_SpriteDef_DefaultImageType_PARAM2;
  static const DefaultImageType ATTR2 =
    GaniInformation_SpriteDef_DefaultImageType_ATTR2;
  static const DefaultImageType PARAM3 =
    GaniInformation_SpriteDef_DefaultImageType_PARAM3;
  static const DefaultImageType ATTR3 =
    GaniInformation_SpriteDef_DefaultImageType_ATTR3;
  static inline bool DefaultImageType_IsValid(int value) {
    return GaniInformation_SpriteDef_DefaultImageType_IsValid(value);
  }
  static const DefaultImageType DefaultImageType_MIN =
    GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_MIN;
  static const DefaultImageType DefaultImageType_MAX =
    GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_MAX;
  static const int DefaultImageType_ARRAYSIZE =
    GaniInformation_SpriteDef_DefaultImageType_DefaultImageType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  DefaultImageType_descriptor() {
    return GaniInformation_SpriteDef_DefaultImageType_descriptor();
  }
  static inline const ::std::string& DefaultImageType_Name(DefaultImageType value) {
    return GaniInformation_SpriteDef_DefaultImageType_Name(value);
  }
  static inline bool DefaultImageType_Parse(const ::std::string& name,
      DefaultImageType* value) {
    return GaniInformation_SpriteDef_DefaultImageType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // optional string image = 2;
  bool has_image() const;
  void clear_image();
  static const int kImageFieldNumber = 2;
  const ::std::string& image() const;
  void set_image(const ::std::string& value);
  #if LANG_CXX11
  void set_image(::std::string&& value);
  #endif
  void set_image(const char* value);
  void set_image(const char* value, size_t size);
  ::std::string* mutable_image();
  ::std::string* release_image();
  void set_allocated_image(::std::string* image);

  // optional string name = 7;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 7;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // optional uint32 index = 1;
  bool has_index() const;
  void clear_index();
  static const int kIndexFieldNumber = 1;
  ::google::protobuf::uint32 index() const;
  void set_index(::google::protobuf::uint32 value);

  // optional int32 offX = 3;
  bool has_offx() const;
  void clear_offx();
  static const int kOffXFieldNumber = 3;
  ::google::protobuf::int32 offx() const;
  void set_offx(::google::protobuf::int32 value);

  // optional int32 offY = 4;
  bool has_offy() const;
  void clear_offy();
  static const int kOffYFieldNumber = 4;
  ::google::protobuf::int32 offy() const;
  void set_offy(::google::protobuf::int32 value);

  // optional int32 width = 5;
  bool has_width() const;
  void clear_width();
  static const int kWidthFieldNumber = 5;
  ::google::protobuf::int32 width() const;
  void set_width(::google::protobuf::int32 value);

  // optional int32 height = 6;
  bool has_height() const;
  void clear_height();
  static const int kHeightFieldNumber = 6;
  ::google::protobuf::int32 height() const;
  void set_height(::google::protobuf::int32 value);

  // optional .GaniInformation.SpriteDef.DefaultImageType defaultImage = 8;
  bool has_defaultimage() const;
  void clear_defaultimage();
  static const int kDefaultImageFieldNumber = 8;
  ::GaniInformation_SpriteDef_DefaultImageType defaultimage() const;
  void set_defaultimage(::GaniInformation_SpriteDef_DefaultImageType value);

  // @@protoc_insertion_point(class_scope:GaniInformation.SpriteDef)
 private:
  void set_has_index();
  void clear_has_index();
  void set_has_image();
  void clear_has_image();
  void set_has_offx();
  void clear_has_offx();
  void set_has_offy();
  void clear_has_offy();
  void set_has_width();
  void clear_has_width();
  void set_has_height();
  void clear_has_height();
  void set_has_name();
  void clear_has_name();
  void set_has_defaultimage();
  void clear_has_defaultimage();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr image_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint32 index_;
  ::google::protobuf::int32 offx_;
  ::google::protobuf::int32 offy_;
  ::google::protobuf::int32 width_;
  ::google::protobuf::int32 height_;
  int defaultimage_;
  friend struct ::protobuf_test_2eproto::TableStruct;
  friend void ::protobuf_test_2eproto::InitDefaultsGaniInformation_SpriteDefImpl();
};
// -------------------------------------------------------------------

class GaniInformation : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:GaniInformation) */ {
 public:
  GaniInformation();
  virtual ~GaniInformation();

  GaniInformation(const GaniInformation& from);

  inline GaniInformation& operator=(const GaniInformation& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  GaniInformation(GaniInformation&& from) noexcept
    : GaniInformation() {
    *this = ::std::move(from);
  }

  inline GaniInformation& operator=(GaniInformation&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GaniInformation& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GaniInformation* internal_default_instance() {
    return reinterpret_cast<const GaniInformation*>(
               &_GaniInformation_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(GaniInformation* other);
  friend void swap(GaniInformation& a, GaniInformation& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline GaniInformation* New() const PROTOBUF_FINAL { return New(NULL); }

  GaniInformation* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const GaniInformation& from);
  void MergeFrom(const GaniInformation& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(GaniInformation* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  typedef GaniInformation_SpriteDef SpriteDef;

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:GaniInformation)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  friend struct ::protobuf_test_2eproto::TableStruct;
  friend void ::protobuf_test_2eproto::InitDefaultsGaniInformationImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GaniInformation_SpriteDef

// optional uint32 index = 1;
inline bool GaniInformation_SpriteDef::has_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_index() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GaniInformation_SpriteDef::clear_has_index() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GaniInformation_SpriteDef::clear_index() {
  index_ = 0u;
  clear_has_index();
}
inline ::google::protobuf::uint32 GaniInformation_SpriteDef::index() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.index)
  return index_;
}
inline void GaniInformation_SpriteDef::set_index(::google::protobuf::uint32 value) {
  set_has_index();
  index_ = value;
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.index)
}

// optional string image = 2;
inline bool GaniInformation_SpriteDef::has_image() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_image() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GaniInformation_SpriteDef::clear_has_image() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GaniInformation_SpriteDef::clear_image() {
  image_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_image();
}
inline const ::std::string& GaniInformation_SpriteDef::image() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.image)
  return image_.GetNoArena();
}
inline void GaniInformation_SpriteDef::set_image(const ::std::string& value) {
  set_has_image();
  image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.image)
}
#if LANG_CXX11
inline void GaniInformation_SpriteDef::set_image(::std::string&& value) {
  set_has_image();
  image_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:GaniInformation.SpriteDef.image)
}
#endif
inline void GaniInformation_SpriteDef::set_image(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_image();
  image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:GaniInformation.SpriteDef.image)
}
inline void GaniInformation_SpriteDef::set_image(const char* value, size_t size) {
  set_has_image();
  image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:GaniInformation.SpriteDef.image)
}
inline ::std::string* GaniInformation_SpriteDef::mutable_image() {
  set_has_image();
  // @@protoc_insertion_point(field_mutable:GaniInformation.SpriteDef.image)
  return image_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GaniInformation_SpriteDef::release_image() {
  // @@protoc_insertion_point(field_release:GaniInformation.SpriteDef.image)
  clear_has_image();
  return image_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GaniInformation_SpriteDef::set_allocated_image(::std::string* image) {
  if (image != NULL) {
    set_has_image();
  } else {
    clear_has_image();
  }
  image_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), image);
  // @@protoc_insertion_point(field_set_allocated:GaniInformation.SpriteDef.image)
}

// optional int32 offX = 3;
inline bool GaniInformation_SpriteDef::has_offx() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_offx() {
  _has_bits_[0] |= 0x00000008u;
}
inline void GaniInformation_SpriteDef::clear_has_offx() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void GaniInformation_SpriteDef::clear_offx() {
  offx_ = 0;
  clear_has_offx();
}
inline ::google::protobuf::int32 GaniInformation_SpriteDef::offx() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.offX)
  return offx_;
}
inline void GaniInformation_SpriteDef::set_offx(::google::protobuf::int32 value) {
  set_has_offx();
  offx_ = value;
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.offX)
}

// optional int32 offY = 4;
inline bool GaniInformation_SpriteDef::has_offy() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_offy() {
  _has_bits_[0] |= 0x00000010u;
}
inline void GaniInformation_SpriteDef::clear_has_offy() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void GaniInformation_SpriteDef::clear_offy() {
  offy_ = 0;
  clear_has_offy();
}
inline ::google::protobuf::int32 GaniInformation_SpriteDef::offy() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.offY)
  return offy_;
}
inline void GaniInformation_SpriteDef::set_offy(::google::protobuf::int32 value) {
  set_has_offy();
  offy_ = value;
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.offY)
}

// optional int32 width = 5;
inline bool GaniInformation_SpriteDef::has_width() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_width() {
  _has_bits_[0] |= 0x00000020u;
}
inline void GaniInformation_SpriteDef::clear_has_width() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void GaniInformation_SpriteDef::clear_width() {
  width_ = 0;
  clear_has_width();
}
inline ::google::protobuf::int32 GaniInformation_SpriteDef::width() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.width)
  return width_;
}
inline void GaniInformation_SpriteDef::set_width(::google::protobuf::int32 value) {
  set_has_width();
  width_ = value;
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.width)
}

// optional int32 height = 6;
inline bool GaniInformation_SpriteDef::has_height() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_height() {
  _has_bits_[0] |= 0x00000040u;
}
inline void GaniInformation_SpriteDef::clear_has_height() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void GaniInformation_SpriteDef::clear_height() {
  height_ = 0;
  clear_has_height();
}
inline ::google::protobuf::int32 GaniInformation_SpriteDef::height() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.height)
  return height_;
}
inline void GaniInformation_SpriteDef::set_height(::google::protobuf::int32 value) {
  set_has_height();
  height_ = value;
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.height)
}

// optional string name = 7;
inline bool GaniInformation_SpriteDef::has_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GaniInformation_SpriteDef::clear_has_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GaniInformation_SpriteDef::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& GaniInformation_SpriteDef::name() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.name)
  return name_.GetNoArena();
}
inline void GaniInformation_SpriteDef::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.name)
}
#if LANG_CXX11
inline void GaniInformation_SpriteDef::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:GaniInformation.SpriteDef.name)
}
#endif
inline void GaniInformation_SpriteDef::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:GaniInformation.SpriteDef.name)
}
inline void GaniInformation_SpriteDef::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:GaniInformation.SpriteDef.name)
}
inline ::std::string* GaniInformation_SpriteDef::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:GaniInformation.SpriteDef.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GaniInformation_SpriteDef::release_name() {
  // @@protoc_insertion_point(field_release:GaniInformation.SpriteDef.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GaniInformation_SpriteDef::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:GaniInformation.SpriteDef.name)
}

// optional .GaniInformation.SpriteDef.DefaultImageType defaultImage = 8;
inline bool GaniInformation_SpriteDef::has_defaultimage() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void GaniInformation_SpriteDef::set_has_defaultimage() {
  _has_bits_[0] |= 0x00000080u;
}
inline void GaniInformation_SpriteDef::clear_has_defaultimage() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void GaniInformation_SpriteDef::clear_defaultimage() {
  defaultimage_ = 0;
  clear_has_defaultimage();
}
inline ::GaniInformation_SpriteDef_DefaultImageType GaniInformation_SpriteDef::defaultimage() const {
  // @@protoc_insertion_point(field_get:GaniInformation.SpriteDef.defaultImage)
  return static_cast< ::GaniInformation_SpriteDef_DefaultImageType >(defaultimage_);
}
inline void GaniInformation_SpriteDef::set_defaultimage(::GaniInformation_SpriteDef_DefaultImageType value) {
  assert(::GaniInformation_SpriteDef_DefaultImageType_IsValid(value));
  set_has_defaultimage();
  defaultimage_ = value;
  // @@protoc_insertion_point(field_set:GaniInformation.SpriteDef.defaultImage)
}

// -------------------------------------------------------------------

// GaniInformation

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::GaniInformation_SpriteDef_DefaultImageType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::GaniInformation_SpriteDef_DefaultImageType>() {
  return ::GaniInformation_SpriteDef_DefaultImageType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED