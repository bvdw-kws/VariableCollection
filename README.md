# VariableCollection - Unreal Engine Plugin

This is the **VariableCollection** plugin, providing tools to create variable collections that can be changed at run-time for dynamic data management and configuration systems.

## About VariableCollection

VariableCollection is a flexible gameplay plugin that enables runtime-configurable variable systems within Unreal Engine. It offers:

- **Runtime Variable Management**: Create and modify variable collections during gameplay
- **Type-Safe Variables**: Support for multiple data types with type safety
- **Blueprint Integration**: Complete Blueprint support for designers and developers
- **Property Binding System**: Advanced property linking and binding capabilities
- **Default Value Support**: Fallback values when bindings are not available
- **Function Library**: Comprehensive utility functions for variable operations

## Plugin Description

*Tool to create variable collection that can be changed at run-time.*

This plugin provides a complete solution for managing configurable variables that can be:
- Modified at runtime without code changes
- Bound to external data sources
- Used across Blueprint and C++ systems
- Organized into logical collections for better management

## Core Components

### Variable Types
- **FVariableCollectionFloat**: Runtime-configurable float variables with binding support
- **FVariableCollectionBool**: Boolean variables with dynamic binding capabilities
- **FVariableCollectionInt**: Integer variables for numerical configuration
- **FVariableCollectionVector**: 3D vector variables for spatial data
- **FVariableCollectionRotator**: Rotation variables for orientation data
- **FVariableCollectionCurveFloat**: Curve-based variables for complex data relationships

### Property Binding System
- **Property Linkers**: Type-specific property linking for each variable type
- **Binding Resolution**: Runtime resolution of variable bindings
- **Default Fallback**: Automatic fallback to default values when bindings fail

### Utility Framework
- **UVariableCollectionFunctionLibrary**: Blueprint function library for variable operations
- **VariableCollectionUtils**: C++ utility functions for advanced operations
- **Property Name Discovery**: Dynamic property name enumeration for editor integration

## Key Features

- **Runtime Configuration**: Modify variable values during gameplay execution
- **Type Safety**: Strongly-typed variable system preventing runtime errors
- **Blueprint Integration**: Native Blueprint support with custom nodes and functions
- **Property Binding**: Advanced binding system for linking variables to external data
- **Default Values**: Reliable fallback system when bindings are unavailable
- **Editor Integration**: Designer-friendly interface for variable management
- **Performance Optimized**: Efficient runtime resolution and caching
- **Flexible Architecture**: Extensible system for custom variable types

## Usage Scenarios

VariableCollection is ideal for:

1. **Game Balance**: Runtime tweaking of gameplay parameters
2. **Configuration Systems**: Player preferences and settings management
3. **Level Design**: Designer-configurable level parameters
4. **AI Behavior**: Runtime adjustment of AI parameters and behaviors
5. **Audio Systems**: Dynamic audio parameter management
6. **Visual Effects**: Runtime modification of effect parameters
7. **Difficulty Scaling**: Dynamic difficulty adjustment systems
8. **A/B Testing**: Runtime configuration for feature testing

## Architecture Overview

### Variable System
```
Variable Collection Types
├── Type-Safe Structures (Float, Bool, Int, Vector, Rotator, Curve)
├── Property Binding System
├── Default Value Management
└── Runtime Resolution
```

### Binding Architecture
```
Property Linker System
├── Type-Specific Linkers
├── Binding Resolution
├── Name Discovery
└── Runtime Updates
```

### Blueprint Integration
```
Function Library
├── Variable Creation Functions
├── Value Retrieval Functions
├── Property Name Discovery
└── Type Conversion Utilities
```

## Integration

The plugin integrates with:
- **Blueprint System**: Native Blueprint support with custom function library
- **Property System**: Deep integration with UE property reflection system
- **Editor Tools**: Designer-friendly variable editing and management
- **Runtime Systems**: Efficient runtime variable resolution and updates
- **Type System**: Leverages UE's type system for safety and performance

## Configuration

### Basic Setup
1. **Enable Plugin**: Enable VariableCollection in project plugins
2. **Create Variables**: Use Blueprint or C++ to create variable collection types
3. **Setup Bindings**: Configure property bindings for dynamic data sources
4. **Set Defaults**: Define fallback values for reliable operation

### Blueprint Usage
1. **Make Variables**: Use Make functions to create typed variables
2. **Get Values**: Retrieve variable values in Blueprint logic
3. **Configure Bindings**: Set up property bindings through Blueprint interface
4. **Handle Updates**: Respond to variable changes in gameplay logic

## Best Practices

- **Logical Organization**: Group related variables into logical collections
- **Performance Considerations**: Cache frequently accessed variable values
- **Binding Design**: Design clear binding hierarchies for maintainability
- **Default Values**: Always provide sensible default values
- **Type Consistency**: Use appropriate variable types for data requirements
- **Documentation**: Document variable purposes and expected ranges

## Technical Features

- **Type Safety**: Compile-time type checking for variable operations
- **Property Reflection**: Leverages UE's property system for dynamic binding
- **Memory Efficient**: Optimized memory usage for variable storage
- **Blueprint Native**: Native Blueprint integration without performance overhead
- **Editor Integration**: Seamless editor workflow for variable management
- **Runtime Flexibility**: Dynamic variable modification during gameplay

## API Overview

### Variable Creation
- **MakeVariableCollection_Float()**: Create float variables with binding support
- **MakeVariableCollection_Bool()**: Create boolean variables with defaults
- **MakeVariableCollection_Int()**: Create integer variables with configuration
- **MakeVariableCollection_Vector()**: Create vector variables for spatial data
- **MakeVariableCollection_Rotator()**: Create rotation variables
- **MakeVariableCollection_CurveFloat()**: Create curve-based variables

### Value Access
- **GetVariableCollectionFloatValue()**: Retrieve float variable values
- **GetVariableCollectionBoolValue()**: Get boolean variable states
- **GetVariableCollectionIntValue()**: Access integer variable values
- **GetVariableCollectionVectorValue()**: Get vector variable data
- **GetVariableCollectionRotatorValue()**: Retrieve rotation values
- **GetVariableCollectionCurveFloatValue()**: Access curve data

### Property Discovery
- **GetFloatPropertyNames()**: Discover available float property bindings
- **GetBoolPropertyNames()**: List boolean property options
- **GetIntPropertyNames()**: Enumerate integer property choices
- **GetVectorPropertyNames()**: Get vector property binding options
- **GetRotatorPropertyNames()**: List rotator property bindings
- **GetCurveFloatPropertyNames()**: Discover curve property options

## Variable Types

### Primitive Types
- **Float**: Floating-point numerical values with precision support
- **Bool**: Boolean true/false states with reliable conversion
- **Int**: 32-bit integer values for counting and indexing

### Complex Types
- **Vector**: 3D spatial coordinates and directional data
- **Rotator**: Euler angle rotations for orientation management
- **CurveFloat**: Curve-based data for complex value relationships

### Type Features
- **Default Values**: Reliable fallback when bindings are unavailable
- **Type Conversion**: Automatic conversion operators for seamless usage
- **Binding Support**: Property binding for dynamic data sources
- **Blueprint Integration**: Native Blueprint support for all types

## Property Binding System

### Binding Mechanism
The plugin provides sophisticated property binding that allows:
- **Dynamic Resolution**: Runtime resolution of property references
- **Type Safety**: Compile-time checking of binding compatibility
- **Fallback Handling**: Graceful degradation when bindings fail
- **Performance Optimization**: Caching and efficient update mechanisms

### Binding Configuration
- **Name-Based Binding**: Bind variables using property names
- **Editor Integration**: Visual binding configuration in editor
- **Runtime Updates**: Dynamic binding changes during gameplay
- **Validation**: Automatic validation of binding integrity

## Performance Considerations

- **Binding Resolution**: Optimize binding resolution frequency
- **Caching Strategy**: Implement appropriate caching for frequently accessed variables
- **Memory Usage**: Consider memory footprint of variable collections
- **Update Frequency**: Balance update rates with performance requirements
- **Type Selection**: Choose appropriate variable types for data requirements

## Module Structure

- **VariableCollectionModule**: Main runtime module
  - **Runtime Loading**: Default loading phase for game integration
  - **Content Support**: Enabled for variable collection assets
  - **Default State**: Enabled by default for immediate availability

## Developer Notes

- **Author**: Bastien Van de Walle
- **Category**: Gameplay
- **Version**: 1.0
- **License**: Apache License 2.0
- **Default State**: Enabled by default for immediate use
- **Content Support**: Enabled for variable collection data assets

## Extension Points

The plugin provides extension points for:
- **Custom Variable Types**: Implement specialized variable types
- **Custom Binding Logic**: Extend property binding system
- **Editor Tools**: Create custom editor interfaces for variable management
- **Validation Systems**: Implement custom validation for variable data
- **Serialization**: Extend serialization for custom variable formats

## Advanced Features

### Editor Integration
- **Property Dropdown**: Dynamic property name discovery for editor dropdowns
- **Visual Binding**: Intuitive visual binding configuration
- **Live Preview**: Real-time preview of variable values in editor
- **Validation Feedback**: Immediate feedback on binding validity

### Blueprint Features
- **Native Make Functions**: Blueprint-native variable creation functions
- **Type Conversion**: Automatic type conversion operators
- **Category Organization**: Well-organized Blueprint function categories
- **Parameter Validation**: Runtime parameter validation and error handling

## Configuration Files

### BaseVariableCollection.ini
The plugin includes configuration files for:
- **Default Settings**: Base configuration for variable collection behavior
- **System Parameters**: Core system configuration options
- **Performance Tuning**: Optimization settings for variable operations

## Use Cases

### Game Development
- **Balance Tweaking**: Runtime adjustment of game balance parameters
- **Player Preferences**: Configurable player settings and preferences
- **Level Configuration**: Designer-configurable level parameters

### System Configuration
- **Performance Tuning**: Runtime performance parameter adjustment
- **Feature Flags**: Dynamic feature enabling/disabling
- **Debug Parameters**: Development and debugging variable systems

### Content Creation
- **Asset Parameters**: Configurable asset behavior parameters
- **Effect Configuration**: Dynamic visual and audio effect parameters
- **Animation Settings**: Runtime animation parameter management

## Credits

- **Plugin Development**: Created by Bastien Van de Walle
- **Variable System**: Flexible runtime variable management solution
- **Property Binding**: Advanced property linking and resolution system
- **License**: Released under Apache License 2.0