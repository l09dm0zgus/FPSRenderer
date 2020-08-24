TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++17
CONFIG += sanitizer sanitize_leak
LIBS += -lGLEW -lSOIL  -lglfw -lGL -lX11 -lpthread -lXrandr -lXi
SOURCES += \
        block.cpp \
        blockvertices.cpp \
        camera.cpp \
        libs/glm/detail/glm.cpp \
        main.cpp \
        render.cpp \
        renderobject.cpp \
        scene.cpp \
        shader.cpp \
        sprite.cpp \
        spritevertices.cpp \
        texture.cpp \
        tilesheettexture.cpp \
        transform.cpp \
        vertexatrribute.cpp \
        vertexbuffers.cpp \
        window.cpp


CONFIG += <standard>
HEADERS += \
    IVertices.h \
    block.h \
    blockvertices.h \
    camera.h \
    libs/glm/common.hpp \
    libs/glm/detail/_features.hpp \
    libs/glm/detail/_fixes.hpp \
    libs/glm/detail/_noise.hpp \
    libs/glm/detail/_swizzle.hpp \
    libs/glm/detail/_swizzle_func.hpp \
    libs/glm/detail/_vectorize.hpp \
    libs/glm/detail/compute_common.hpp \
    libs/glm/detail/compute_vector_relational.hpp \
    libs/glm/detail/func_common.inl \
    libs/glm/detail/func_common_simd.inl \
    libs/glm/detail/func_exponential.inl \
    libs/glm/detail/func_exponential_simd.inl \
    libs/glm/detail/func_geometric.inl \
    libs/glm/detail/func_geometric_simd.inl \
    libs/glm/detail/func_integer.inl \
    libs/glm/detail/func_integer_simd.inl \
    libs/glm/detail/func_matrix.inl \
    libs/glm/detail/func_matrix_simd.inl \
    libs/glm/detail/func_packing.inl \
    libs/glm/detail/func_packing_simd.inl \
    libs/glm/detail/func_trigonometric.inl \
    libs/glm/detail/func_trigonometric_simd.inl \
    libs/glm/detail/func_vector_relational.inl \
    libs/glm/detail/func_vector_relational_simd.inl \
    libs/glm/detail/qualifier.hpp \
    libs/glm/detail/setup.hpp \
    libs/glm/detail/type_float.hpp \
    libs/glm/detail/type_half.hpp \
    libs/glm/detail/type_half.inl \
    libs/glm/detail/type_mat2x2.hpp \
    libs/glm/detail/type_mat2x2.inl \
    libs/glm/detail/type_mat2x3.hpp \
    libs/glm/detail/type_mat2x3.inl \
    libs/glm/detail/type_mat2x4.hpp \
    libs/glm/detail/type_mat2x4.inl \
    libs/glm/detail/type_mat3x2.hpp \
    libs/glm/detail/type_mat3x2.inl \
    libs/glm/detail/type_mat3x3.hpp \
    libs/glm/detail/type_mat3x3.inl \
    libs/glm/detail/type_mat3x4.hpp \
    libs/glm/detail/type_mat3x4.inl \
    libs/glm/detail/type_mat4x2.hpp \
    libs/glm/detail/type_mat4x2.inl \
    libs/glm/detail/type_mat4x3.hpp \
    libs/glm/detail/type_mat4x3.inl \
    libs/glm/detail/type_mat4x4.hpp \
    libs/glm/detail/type_mat4x4.inl \
    libs/glm/detail/type_mat4x4_simd.inl \
    libs/glm/detail/type_quat.hpp \
    libs/glm/detail/type_quat.inl \
    libs/glm/detail/type_quat_simd.inl \
    libs/glm/detail/type_vec1.hpp \
    libs/glm/detail/type_vec1.inl \
    libs/glm/detail/type_vec2.hpp \
    libs/glm/detail/type_vec2.inl \
    libs/glm/detail/type_vec3.hpp \
    libs/glm/detail/type_vec3.inl \
    libs/glm/detail/type_vec4.hpp \
    libs/glm/detail/type_vec4.inl \
    libs/glm/detail/type_vec4_simd.inl \
    libs/glm/exponential.hpp \
    libs/glm/ext.hpp \
    libs/glm/ext/matrix_clip_space.hpp \
    libs/glm/ext/matrix_clip_space.inl \
    libs/glm/ext/matrix_common.hpp \
    libs/glm/ext/matrix_common.inl \
    libs/glm/ext/matrix_double2x2.hpp \
    libs/glm/ext/matrix_double2x2_precision.hpp \
    libs/glm/ext/matrix_double2x3.hpp \
    libs/glm/ext/matrix_double2x3_precision.hpp \
    libs/glm/ext/matrix_double2x4.hpp \
    libs/glm/ext/matrix_double2x4_precision.hpp \
    libs/glm/ext/matrix_double3x2.hpp \
    libs/glm/ext/matrix_double3x2_precision.hpp \
    libs/glm/ext/matrix_double3x3.hpp \
    libs/glm/ext/matrix_double3x3_precision.hpp \
    libs/glm/ext/matrix_double3x4.hpp \
    libs/glm/ext/matrix_double3x4_precision.hpp \
    libs/glm/ext/matrix_double4x2.hpp \
    libs/glm/ext/matrix_double4x2_precision.hpp \
    libs/glm/ext/matrix_double4x3.hpp \
    libs/glm/ext/matrix_double4x3_precision.hpp \
    libs/glm/ext/matrix_double4x4.hpp \
    libs/glm/ext/matrix_double4x4_precision.hpp \
    libs/glm/ext/matrix_float2x2.hpp \
    libs/glm/ext/matrix_float2x2_precision.hpp \
    libs/glm/ext/matrix_float2x3.hpp \
    libs/glm/ext/matrix_float2x3_precision.hpp \
    libs/glm/ext/matrix_float2x4.hpp \
    libs/glm/ext/matrix_float2x4_precision.hpp \
    libs/glm/ext/matrix_float3x2.hpp \
    libs/glm/ext/matrix_float3x2_precision.hpp \
    libs/glm/ext/matrix_float3x3.hpp \
    libs/glm/ext/matrix_float3x3_precision.hpp \
    libs/glm/ext/matrix_float3x4.hpp \
    libs/glm/ext/matrix_float3x4_precision.hpp \
    libs/glm/ext/matrix_float4x2.hpp \
    libs/glm/ext/matrix_float4x2_precision.hpp \
    libs/glm/ext/matrix_float4x3.hpp \
    libs/glm/ext/matrix_float4x3_precision.hpp \
    libs/glm/ext/matrix_float4x4.hpp \
    libs/glm/ext/matrix_float4x4_precision.hpp \
    libs/glm/ext/matrix_projection.hpp \
    libs/glm/ext/matrix_projection.inl \
    libs/glm/ext/matrix_relational.hpp \
    libs/glm/ext/matrix_relational.inl \
    libs/glm/ext/matrix_transform.hpp \
    libs/glm/ext/matrix_transform.inl \
    libs/glm/ext/quaternion_common.hpp \
    libs/glm/ext/quaternion_common.inl \
    libs/glm/ext/quaternion_common_simd.inl \
    libs/glm/ext/quaternion_double.hpp \
    libs/glm/ext/quaternion_double_precision.hpp \
    libs/glm/ext/quaternion_exponential.hpp \
    libs/glm/ext/quaternion_exponential.inl \
    libs/glm/ext/quaternion_float.hpp \
    libs/glm/ext/quaternion_float_precision.hpp \
    libs/glm/ext/quaternion_geometric.hpp \
    libs/glm/ext/quaternion_geometric.inl \
    libs/glm/ext/quaternion_relational.hpp \
    libs/glm/ext/quaternion_relational.inl \
    libs/glm/ext/quaternion_transform.hpp \
    libs/glm/ext/quaternion_transform.inl \
    libs/glm/ext/quaternion_trigonometric.hpp \
    libs/glm/ext/quaternion_trigonometric.inl \
    libs/glm/ext/scalar_common.hpp \
    libs/glm/ext/scalar_common.inl \
    libs/glm/ext/scalar_constants.hpp \
    libs/glm/ext/scalar_constants.inl \
    libs/glm/ext/scalar_int_sized.hpp \
    libs/glm/ext/scalar_integer.hpp \
    libs/glm/ext/scalar_integer.inl \
    libs/glm/ext/scalar_packing.hpp \
    libs/glm/ext/scalar_packing.inl \
    libs/glm/ext/scalar_relational.hpp \
    libs/glm/ext/scalar_relational.inl \
    libs/glm/ext/scalar_uint_sized.hpp \
    libs/glm/ext/scalar_ulp.hpp \
    libs/glm/ext/scalar_ulp.inl \
    libs/glm/ext/vector_bool1.hpp \
    libs/glm/ext/vector_bool1_precision.hpp \
    libs/glm/ext/vector_bool2.hpp \
    libs/glm/ext/vector_bool2_precision.hpp \
    libs/glm/ext/vector_bool3.hpp \
    libs/glm/ext/vector_bool3_precision.hpp \
    libs/glm/ext/vector_bool4.hpp \
    libs/glm/ext/vector_bool4_precision.hpp \
    libs/glm/ext/vector_common.hpp \
    libs/glm/ext/vector_common.inl \
    libs/glm/ext/vector_double1.hpp \
    libs/glm/ext/vector_double1_precision.hpp \
    libs/glm/ext/vector_double2.hpp \
    libs/glm/ext/vector_double2_precision.hpp \
    libs/glm/ext/vector_double3.hpp \
    libs/glm/ext/vector_double3_precision.hpp \
    libs/glm/ext/vector_double4.hpp \
    libs/glm/ext/vector_double4_precision.hpp \
    libs/glm/ext/vector_float1.hpp \
    libs/glm/ext/vector_float1_precision.hpp \
    libs/glm/ext/vector_float2.hpp \
    libs/glm/ext/vector_float2_precision.hpp \
    libs/glm/ext/vector_float3.hpp \
    libs/glm/ext/vector_float3_precision.hpp \
    libs/glm/ext/vector_float4.hpp \
    libs/glm/ext/vector_float4_precision.hpp \
    libs/glm/ext/vector_int1.hpp \
    libs/glm/ext/vector_int1_precision.hpp \
    libs/glm/ext/vector_int1_sized.hpp \
    libs/glm/ext/vector_int2.hpp \
    libs/glm/ext/vector_int2_precision.hpp \
    libs/glm/ext/vector_int2_sized.hpp \
    libs/glm/ext/vector_int3.hpp \
    libs/glm/ext/vector_int3_precision.hpp \
    libs/glm/ext/vector_int3_sized.hpp \
    libs/glm/ext/vector_int4.hpp \
    libs/glm/ext/vector_int4_precision.hpp \
    libs/glm/ext/vector_int4_sized.hpp \
    libs/glm/ext/vector_integer.hpp \
    libs/glm/ext/vector_integer.inl \
    libs/glm/ext/vector_packing.hpp \
    libs/glm/ext/vector_packing.inl \
    libs/glm/ext/vector_relational.hpp \
    libs/glm/ext/vector_relational.inl \
    libs/glm/ext/vector_uint1.hpp \
    libs/glm/ext/vector_uint1_precision.hpp \
    libs/glm/ext/vector_uint1_sized.hpp \
    libs/glm/ext/vector_uint2.hpp \
    libs/glm/ext/vector_uint2_precision.hpp \
    libs/glm/ext/vector_uint2_sized.hpp \
    libs/glm/ext/vector_uint3.hpp \
    libs/glm/ext/vector_uint3_precision.hpp \
    libs/glm/ext/vector_uint3_sized.hpp \
    libs/glm/ext/vector_uint4.hpp \
    libs/glm/ext/vector_uint4_precision.hpp \
    libs/glm/ext/vector_uint4_sized.hpp \
    libs/glm/ext/vector_ulp.hpp \
    libs/glm/ext/vector_ulp.inl \
    libs/glm/fwd.hpp \
    libs/glm/geometric.hpp \
    libs/glm/glm.hpp \
    libs/glm/gtc/bitfield.hpp \
    libs/glm/gtc/bitfield.inl \
    libs/glm/gtc/color_space.hpp \
    libs/glm/gtc/color_space.inl \
    libs/glm/gtc/constants.hpp \
    libs/glm/gtc/constants.inl \
    libs/glm/gtc/epsilon.hpp \
    libs/glm/gtc/epsilon.inl \
    libs/glm/gtc/integer.hpp \
    libs/glm/gtc/integer.inl \
    libs/glm/gtc/matrix_access.hpp \
    libs/glm/gtc/matrix_access.inl \
    libs/glm/gtc/matrix_integer.hpp \
    libs/glm/gtc/matrix_inverse.hpp \
    libs/glm/gtc/matrix_inverse.inl \
    libs/glm/gtc/matrix_transform.hpp \
    libs/glm/gtc/matrix_transform.inl \
    libs/glm/gtc/noise.hpp \
    libs/glm/gtc/noise.inl \
    libs/glm/gtc/packing.hpp \
    libs/glm/gtc/packing.inl \
    libs/glm/gtc/quaternion.hpp \
    libs/glm/gtc/quaternion.inl \
    libs/glm/gtc/quaternion_simd.inl \
    libs/glm/gtc/random.hpp \
    libs/glm/gtc/random.inl \
    libs/glm/gtc/reciprocal.hpp \
    libs/glm/gtc/reciprocal.inl \
    libs/glm/gtc/round.hpp \
    libs/glm/gtc/round.inl \
    libs/glm/gtc/type_aligned.hpp \
    libs/glm/gtc/type_precision.hpp \
    libs/glm/gtc/type_precision.inl \
    libs/glm/gtc/type_ptr.hpp \
    libs/glm/gtc/type_ptr.inl \
    libs/glm/gtc/ulp.hpp \
    libs/glm/gtc/ulp.inl \
    libs/glm/gtc/vec1.hpp \
    libs/glm/gtx/associated_min_max.hpp \
    libs/glm/gtx/associated_min_max.inl \
    libs/glm/gtx/bit.hpp \
    libs/glm/gtx/bit.inl \
    libs/glm/gtx/closest_point.hpp \
    libs/glm/gtx/closest_point.inl \
    libs/glm/gtx/color_encoding.hpp \
    libs/glm/gtx/color_encoding.inl \
    libs/glm/gtx/color_space.hpp \
    libs/glm/gtx/color_space.inl \
    libs/glm/gtx/color_space_YCoCg.hpp \
    libs/glm/gtx/color_space_YCoCg.inl \
    libs/glm/gtx/common.hpp \
    libs/glm/gtx/common.inl \
    libs/glm/gtx/compatibility.hpp \
    libs/glm/gtx/compatibility.inl \
    libs/glm/gtx/component_wise.hpp \
    libs/glm/gtx/component_wise.inl \
    libs/glm/gtx/dual_quaternion.hpp \
    libs/glm/gtx/dual_quaternion.inl \
    libs/glm/gtx/easing.hpp \
    libs/glm/gtx/easing.inl \
    libs/glm/gtx/euler_angles.hpp \
    libs/glm/gtx/euler_angles.inl \
    libs/glm/gtx/extend.hpp \
    libs/glm/gtx/extend.inl \
    libs/glm/gtx/extended_min_max.hpp \
    libs/glm/gtx/extended_min_max.inl \
    libs/glm/gtx/exterior_product.hpp \
    libs/glm/gtx/exterior_product.inl \
    libs/glm/gtx/fast_exponential.hpp \
    libs/glm/gtx/fast_exponential.inl \
    libs/glm/gtx/fast_square_root.hpp \
    libs/glm/gtx/fast_square_root.inl \
    libs/glm/gtx/fast_trigonometry.hpp \
    libs/glm/gtx/fast_trigonometry.inl \
    libs/glm/gtx/float_notmalize.inl \
    libs/glm/gtx/functions.hpp \
    libs/glm/gtx/functions.inl \
    libs/glm/gtx/gradient_paint.hpp \
    libs/glm/gtx/gradient_paint.inl \
    libs/glm/gtx/handed_coordinate_space.hpp \
    libs/glm/gtx/handed_coordinate_space.inl \
    libs/glm/gtx/hash.hpp \
    libs/glm/gtx/hash.inl \
    libs/glm/gtx/integer.hpp \
    libs/glm/gtx/integer.inl \
    libs/glm/gtx/intersect.hpp \
    libs/glm/gtx/intersect.inl \
    libs/glm/gtx/io.hpp \
    libs/glm/gtx/io.inl \
    libs/glm/gtx/log_base.hpp \
    libs/glm/gtx/log_base.inl \
    libs/glm/gtx/matrix_cross_product.hpp \
    libs/glm/gtx/matrix_cross_product.inl \
    libs/glm/gtx/matrix_decompose.hpp \
    libs/glm/gtx/matrix_decompose.inl \
    libs/glm/gtx/matrix_factorisation.hpp \
    libs/glm/gtx/matrix_factorisation.inl \
    libs/glm/gtx/matrix_interpolation.hpp \
    libs/glm/gtx/matrix_interpolation.inl \
    libs/glm/gtx/matrix_major_storage.hpp \
    libs/glm/gtx/matrix_major_storage.inl \
    libs/glm/gtx/matrix_operation.hpp \
    libs/glm/gtx/matrix_operation.inl \
    libs/glm/gtx/matrix_query.hpp \
    libs/glm/gtx/matrix_query.inl \
    libs/glm/gtx/matrix_transform_2d.hpp \
    libs/glm/gtx/matrix_transform_2d.inl \
    libs/glm/gtx/mixed_product.hpp \
    libs/glm/gtx/mixed_product.inl \
    libs/glm/gtx/norm.hpp \
    libs/glm/gtx/norm.inl \
    libs/glm/gtx/normal.hpp \
    libs/glm/gtx/normal.inl \
    libs/glm/gtx/normalize_dot.hpp \
    libs/glm/gtx/normalize_dot.inl \
    libs/glm/gtx/number_precision.hpp \
    libs/glm/gtx/number_precision.inl \
    libs/glm/gtx/optimum_pow.hpp \
    libs/glm/gtx/optimum_pow.inl \
    libs/glm/gtx/orthonormalize.hpp \
    libs/glm/gtx/orthonormalize.inl \
    libs/glm/gtx/perpendicular.hpp \
    libs/glm/gtx/perpendicular.inl \
    libs/glm/gtx/polar_coordinates.hpp \
    libs/glm/gtx/polar_coordinates.inl \
    libs/glm/gtx/projection.hpp \
    libs/glm/gtx/projection.inl \
    libs/glm/gtx/quaternion.hpp \
    libs/glm/gtx/quaternion.inl \
    libs/glm/gtx/range.hpp \
    libs/glm/gtx/raw_data.hpp \
    libs/glm/gtx/raw_data.inl \
    libs/glm/gtx/rotate_normalized_axis.hpp \
    libs/glm/gtx/rotate_normalized_axis.inl \
    libs/glm/gtx/rotate_vector.hpp \
    libs/glm/gtx/rotate_vector.inl \
    libs/glm/gtx/scalar_multiplication.hpp \
    libs/glm/gtx/scalar_relational.hpp \
    libs/glm/gtx/scalar_relational.inl \
    libs/glm/gtx/spline.hpp \
    libs/glm/gtx/spline.inl \
    libs/glm/gtx/std_based_type.hpp \
    libs/glm/gtx/std_based_type.inl \
    libs/glm/gtx/string_cast.hpp \
    libs/glm/gtx/string_cast.inl \
    libs/glm/gtx/texture.hpp \
    libs/glm/gtx/texture.inl \
    libs/glm/gtx/transform.hpp \
    libs/glm/gtx/transform.inl \
    libs/glm/gtx/transform2.hpp \
    libs/glm/gtx/transform2.inl \
    libs/glm/gtx/type_aligned.hpp \
    libs/glm/gtx/type_aligned.inl \
    libs/glm/gtx/type_trait.hpp \
    libs/glm/gtx/type_trait.inl \
    libs/glm/gtx/vec_swizzle.hpp \
    libs/glm/gtx/vector_angle.hpp \
    libs/glm/gtx/vector_angle.inl \
    libs/glm/gtx/vector_query.hpp \
    libs/glm/gtx/vector_query.inl \
    libs/glm/gtx/wrap.hpp \
    libs/glm/gtx/wrap.inl \
    libs/glm/integer.hpp \
    libs/glm/mat2x2.hpp \
    libs/glm/mat2x3.hpp \
    libs/glm/mat2x4.hpp \
    libs/glm/mat3x2.hpp \
    libs/glm/mat3x3.hpp \
    libs/glm/mat3x4.hpp \
    libs/glm/mat4x2.hpp \
    libs/glm/mat4x3.hpp \
    libs/glm/mat4x4.hpp \
    libs/glm/matrix.hpp \
    libs/glm/packing.hpp \
    libs/glm/simd/common.h \
    libs/glm/simd/exponential.h \
    libs/glm/simd/geometric.h \
    libs/glm/simd/integer.h \
    libs/glm/simd/matrix.h \
    libs/glm/simd/neon.h \
    libs/glm/simd/packing.h \
    libs/glm/simd/platform.h \
    libs/glm/simd/trigonometric.h \
    libs/glm/simd/vector_relational.h \
    libs/glm/trigonometric.hpp \
    libs/glm/vec2.hpp \
    libs/glm/vec3.hpp \
    libs/glm/vec4.hpp \
    libs/glm/vector_relational.hpp \
    libs/ini.h \
    render.h \
    renderobject.h \
    scene.h \
    shader.h \
    sprite.h \
    spritevertices.h \
    texture.h \
    tilesheettexture.h \
    transform.h \
    vertexatrribute.h \
    vertexbuffers.h \
    window.h

#unix|win32: LIBS += -lreactphysics3d
